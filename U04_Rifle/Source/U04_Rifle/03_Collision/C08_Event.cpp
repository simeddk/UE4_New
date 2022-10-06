#include "C08_Event.h"
#include "Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AC08_Event::AC08_Event()
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

void AC08_Event::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AC08_Event::ActorBeginOverlap);
}

void AC08_Event::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnEventBeginOverlap.IsBound())
	{
		int32 index = UKismetMathLibrary::RandomIntegerInRange(0, 2);

		OnEventBeginOverlap.Broadcast(index);
	}
}

