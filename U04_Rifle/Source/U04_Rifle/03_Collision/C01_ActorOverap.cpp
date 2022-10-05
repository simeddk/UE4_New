#include "C01_ActorOverap.h"
#include "Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AC01_ActorOverap::AC01_ActorOverap()
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

void AC01_ActorOverap::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AC01_ActorOverap::ActorBeginOverlap);
}

void AC01_ActorOverap::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	CLog::Log(OtherActor->GetName());
}

