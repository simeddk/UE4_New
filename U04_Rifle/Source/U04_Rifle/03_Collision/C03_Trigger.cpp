#include "C03_Trigger.h"
#include "Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AC03_Trigger::AC03_Trigger()
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

void AC03_Trigger::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AC03_Trigger::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC03_Trigger::ActorEndOverlap);
}

void AC03_Trigger::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxBeginOverlap.IsBound())
		OnBoxBeginOverlap.Execute();

	if (OnBoxRandomOverlap.IsBound())
	{
		FString str = OnBoxRandomOverlap.Execute(GetRandomColor());
		str = FString("Return Value is...") + str;

		CLog::Log(str);
	}
}

void AC03_Trigger::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxEndOverlap.IsBound())
		OnBoxEndOverlap.Execute();
}

FLinearColor AC03_Trigger::GetRandomColor()
{
	FLinearColor color;
	color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.A = 1.f;

	return color;
}

