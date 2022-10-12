#include "C05_ExplosionTrigger.h"
#include "Global.h"
#include "C04_Explosion.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AC05_ExplosionTrigger::AC05_ExplosionTrigger()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Box->bHiddenInGame = false;
	Box->SetRelativeScale3D(FVector(3));

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->TextRenderColor = FColor::Black;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());
}

void AC05_ExplosionTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC04_Explosion::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	AC04_Explosion* explosion = Cast<AC04_Explosion>(actors[0]);

	OnActorBeginOverlap.AddDynamic(explosion, &AC04_Explosion::ActorBeginOverlap);
}

