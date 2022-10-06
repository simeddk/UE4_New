#include "C07_SpotLights.h"
#include "Global.h"
#include "C05_MultiTrigger.h"
#include "Components/TextRenderComponent.h"
#include "Components/SpotLightComponent.h"

AC07_SpotLights::AC07_SpotLights()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);


	for (int32 i = 0; i < 3; i++)
	{
		FString str;
		str.Append("SpotLight");
		str.Append(FString::FromInt(i + 1));

		CHelpers::CreateComponent<USpotLightComponent>(this, &SpotLights[i], FName(str), Scene);
		SpotLights[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		SpotLights[i]->Intensity = 1e+5f;
		SpotLights[i]->OuterConeAngle = 25.f;
	}

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->TextRenderColor = FColor::Black;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());
}

void AC07_SpotLights::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC05_MultiTrigger::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	AC05_MultiTrigger* trigger = Cast<AC05_MultiTrigger>(actors[0]);
	trigger->OnMultiBeginOverlap.AddUFunction(this, "OnLightColor");
}

void AC07_SpotLights::OnLightColor(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
		SpotLights[i]->SetLightColor(FLinearColor(1, 1, 1));

	SpotLights[InIndex]->SetLightColor(InColor);
}

