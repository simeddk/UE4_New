#include "CBullet.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Materials/MaterialInstanceConstant.h"

ACBullet::ACBullet()
{
	CHelpers::CreateComponent(this, &Mesh, "Mesh");
	CHelpers::CreateActorComponent(this, &Projectile, "Projectile");

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/StaticMeshes/SM_Sphere.SM_Sphere'");
	Mesh->SetStaticMesh(mesh);
	
	UMaterialInstanceConstant* material;
	CHelpers::GetAsset<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Materials/MAT_Bullet_Inst.MAT_Bullet_Inst'");
	Mesh->SetMaterial(0, material);

	Mesh->SetRelativeScale3D(FVector(1.0f, 0.025f, 0.025f));
	Mesh->SetCollisionProfileName("NoCollision");

	Projectile->InitialSpeed = 2e+4f;
	Projectile->MaxSpeed = 2e+4f;
	Projectile->ProjectileGravityScale = 0.f;
}

void ACBullet::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(3.f);
}

