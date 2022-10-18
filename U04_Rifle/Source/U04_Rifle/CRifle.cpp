#include "CRifle.h"
#include "Global.h"
#include "IRifle.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystem.h"
#include "Materials/MaterialInstanceConstant.h"

ACRifle* ACRifle::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params;
	params.Owner = InOwner;
	return InWorld->SpawnActor<ACRifle>(params);
}

ACRifle::ACRifle()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<USkeletalMeshComponent>(this, &Mesh, "Mesh");

	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Weapons/Meshes/AR4/SK_AR4.SK_AR4'");
	Mesh->SetSkeletalMesh(mesh);

	CHelpers::GetAsset<UAnimMontage>(&GrabMontage, "AnimMontage'/Game/Character/Animations/Rifle_Grab_Montage.Rifle_Grab_Montage'");
	CHelpers::GetAsset<UAnimMontage>(&UngrabMontage, "AnimMontage'/Game/Character/Animations/Rifle_Ungrab_Montage.Rifle_Ungrab_Montage'");
	CHelpers::GetClass<UCameraShake>(&CameraShakeClass, "Blueprint'/Game/BP_CameraShake.BP_CameraShake_C'");
	CHelpers::GetClass<ACBullet>(&BulletClass, "Blueprint'/Game/BP_CBullet.BP_CBullet_C'");

	CHelpers::GetAsset<UParticleSystem>(&FlashParticle, "ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Muzzleflash.VFX_Muzzleflash'");
	CHelpers::GetAsset<UParticleSystem>(&EjectParticle, "ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Eject_bullet.VFX_Eject_bullet'");
	CHelpers::GetAsset<UParticleSystem>(&ImpactParticle, "ParticleSystem'/Game/Particles_Rifle/Particles/VFX_Impact_Default.VFX_Impact_Default'");
	CHelpers::GetAsset<USoundCue>(&FireSoundCue, "SoundCue'/Game/Sounds/S_RifleShoot_Cue.S_RifleShoot_Cue'");
	CHelpers::GetAsset<UMaterialInstanceConstant>(&DecalMaterial, "MaterialInstanceConstant'/Game/Materials/M_Decal_Inst.M_Decal_Inst'");
}

void ACRifle::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	
	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HolsterSocket
	);
}

void ACRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckFalse(bAiming);
	
	IIRifle* rifleCharacter = Cast<IIRifle>(OwnerCharacter);
	CheckNull(rifleCharacter);

	FVector start, end, direction;
	rifleCharacter->GetAimRay(start, end, direction);

	//DrawDebugLine(GetWorld(), start, end, FColor::Red);

	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel
	(
		hitResult,
		start,
		end,
		ECollisionChannel::ECC_WorldDynamic,
		params
	))
	{
		AStaticMeshActor* meshActor = Cast<AStaticMeshActor>(hitResult.GetActor());
		if (!!meshActor)
		{
			UStaticMeshComponent* meshComp =  Cast<UStaticMeshComponent>(meshActor->GetRootComponent());
			if (!!meshComp)
			{
				if (meshComp->BodyInstance.bSimulatePhysics)
				{
					rifleCharacter->OnFocus();
					return;
				} //if (bSimulatePhysics)
			}//if (meshComp)
		}//if (meshActor)
	}

	rifleCharacter->OffFocus();
}


void ACRifle::Equip()
{
	CheckTrue(bEquipped);
	CheckTrue(bEquipping);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(GrabMontage, 1.75f);
}

void ACRifle::Begin_Equip()
{
	bEquipped = true;

	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HandSocket
	);
}

void ACRifle::End_Equip()
{
	bEquipping = false;
}

void ACRifle::Unequip()
{
	CheckFalse(bEquipped);
	CheckTrue(bEquipping);

	bEquipping = true;
	OwnerCharacter->PlayAnimMontage(UngrabMontage, 1.75f);
}

void ACRifle::Begin_Unequip()
{
	bEquipped = false;

	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HolsterSocket
	);
}

void ACRifle::End_Unequip()
{
	bEquipping = false;
}

void ACRifle::Begin_Aim()
{
	bAiming = true;
}

void ACRifle::End_Aim()
{
	bAiming = false;
}

void ACRifle::Begin_Fire()
{
	CheckFalse(bEquipped);
	CheckTrue(bEquipping);
	CheckFalse(bAiming);
	CheckTrue(bFiring);

	bFiring = true;

	if (bAutoFire == true)
	{
		GetWorld()->GetTimerManager().SetTimer(AutoFireTimer, this, &ACRifle::Firing, 0.1f, true, 0.f);
		return;
	}

	Firing();
}

void ACRifle::End_Fire()
{
	bFiring = false;
	
	if (bAutoFire == true)
		GetWorld()->GetTimerManager().ClearTimer(AutoFireTimer);
}

void ACRifle::Firing()
{
	IIRifle* rifleCharacter = Cast<IIRifle>(OwnerCharacter);
	CheckNull(rifleCharacter);

	ACPlayer* player = Cast<ACPlayer>(OwnerCharacter);
	if (!!player)
	{
		APlayerController* controller = player->GetController<APlayerController>();
		controller->PlayerCameraManager->PlayCameraShake(CameraShakeClass);
	}

	FVector start, end, direction;
	rifleCharacter->GetAimRay(start, end, direction);

	FVector muzzleLocation = Mesh->GetSocketLocation("MuzzleFlash");
	GetWorld()->SpawnActor<ACBullet>(BulletClass, muzzleLocation, direction.Rotation());

	UGameplayStatics::SpawnEmitterAttached(FlashParticle, Mesh, "MuzzleFlash");
	UGameplayStatics::SpawnEmitterAttached(EjectParticle, Mesh, "EjectBullet");
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSoundCue, muzzleLocation);

	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(OwnerCharacter);

	FHitResult hitResult;
	if (GetWorld()->LineTraceSingleByChannel
	(
		hitResult,
		start,
		end,
		ECollisionChannel::ECC_Visibility,
		params
	))
	{
		FRotator decalRotator = hitResult.ImpactNormal.Rotation();
		UGameplayStatics::SpawnDecalAtLocation(GetWorld(), DecalMaterial, FVector(5), hitResult.Location, decalRotator, 10.f);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, hitResult.Location, decalRotator);
	}

	

	if (GetWorld()->LineTraceSingleByChannel
	(
		hitResult,
		start,
		end,
		ECollisionChannel::ECC_WorldDynamic,
		params
	))
	{
		AStaticMeshActor* meshActor = Cast<AStaticMeshActor>(hitResult.GetActor());
		if (!!meshActor)
		{
			UStaticMeshComponent* meshComp = Cast<UStaticMeshComponent>(meshActor->GetRootComponent());
			if (!!meshComp)
			{
				if (meshComp->BodyInstance.bSimulatePhysics)
				{
					direction = meshActor->GetActorLocation() - OwnerCharacter->GetActorLocation();
					direction.Normalize();

					meshComp->AddImpulseAtLocation(direction * 3000.f, OwnerCharacter->GetActorLocation());
					return;
				} //if (bSimulatePhysics)
			}//if (meshComp)
		}//if (meshActor)
	}

}
