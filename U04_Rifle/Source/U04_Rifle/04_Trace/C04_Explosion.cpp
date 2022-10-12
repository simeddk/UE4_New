#include "C04_Explosion.h"
#include "Global.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/TextRenderComponent.h"

AC04_Explosion::AC04_Explosion()
{
	CHelpers::CreateComponent<UParticleSystemComponent>(this, &Partcle, "Partcle");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Partcle);

	UParticleSystem* particle;
	CHelpers::GetAsset<UParticleSystem>(&particle, "ParticleSystem'/Game/Explosions/Particles/P_Destruction1.P_Destruction1'");
	Partcle->SetTemplate(particle);

	Partcle->bAutoActivate = false;

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->TextRenderColor = FColor::Black;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString("Boom Here!");
}

void AC04_Explosion::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC04_Explosion::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	FVector start = GetActorLocation();
	FVector end = FVector(start.X, start.Y, start.Z + 10);

	TArray<TEnumAsByte<EObjectTypeQuery>> queries;
	queries.Add(EObjectTypeQuery::ObjectTypeQuery4);
	
	TArray<AActor*> ignores;
	TArray<FHitResult> hitResults;


	if (UKismetSystemLibrary::SphereTraceMultiForObjects
	(
		GetWorld(),
		start,
		end,
		1000,
		queries,
		false,
		ignores,
		EDrawDebugTrace::ForOneFrame,
		hitResults,
		true
	))
	{

		Partcle->ResetParticles();
		Partcle->SetActive(true);

		for (const FHitResult& hitResult : hitResults)
		{
			UStaticMeshComponent* meshComp = Cast<UStaticMeshComponent>(hitResult.GetActor()->GetRootComponent());
			if (!!meshComp)
				meshComp->AddRadialImpulse
				(
					GetActorLocation(),
					1000,
					meshComp->GetMass() * 550.f,
					ERadialImpulseFalloff::RIF_Linear
				);
		}
	}
}

