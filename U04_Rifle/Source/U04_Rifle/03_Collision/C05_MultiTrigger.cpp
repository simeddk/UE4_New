#include "C05_MultiTrigger.h"
#include "Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AC05_MultiTrigger::AC05_MultiTrigger()
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

void AC05_MultiTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AC05_MultiTrigger::ActorBeginOverlap);
}

void AC05_MultiTrigger::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);
	FLinearColor color = FLinearColor::MakeRandomColor();
	color.A = 1.f;

	if (OnMultiBeginOverlap.IsBound())
		OnMultiBeginOverlap.Broadcast(index, color);
}
