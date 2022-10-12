#include "C09_Particles.h"
#include "Global.h"
#include "C08_Event.h"
#include "Components/TextRenderComponent.h"
#include "Particles/ParticleSystem.h"

AC09_Particles::AC09_Particles()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->TextRenderColor = FColor::Black;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	CHelpers::GetAsset<UParticleSystem>(&Particles[0], "ParticleSystem'/Game/Explosions/Particles/P_Destruction1.P_Destruction1'");
	CHelpers::GetAsset<UParticleSystem>(&Particles[1], "ParticleSystem'/Game/Particles/P_Heal.P_Heal'");
	CHelpers::GetAsset<UParticleSystem>(&Particles[2], "ParticleSystem'/Game/Particles/P_WarpEnd.P_WarpEnd'");
}

void AC09_Particles::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC08_Event::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	AC08_Event* eventObj = Cast<AC08_Event>(actors[0]);
	eventObj->OnEventBeginOverlap.AddUFunction(this, "PlayParticle");
}

void AC09_Particles::PlayParticle(int32 InIndex)
{
	FTransform transform;
	transform.SetLocation(GetActorLocation());
	
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particles[InIndex], transform);
}

