#include "C04_Light.h"
#include "Global.h"
#include "C03_Trigger.h"
#include "Components/TextRenderComponent.h"
#include "Components/PointLightComponent.h"

AC04_Light::AC04_Light()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	CHelpers::CreateComponent<UPointLightComponent>(this, &Light1, "Light1", Scene);
	CHelpers::CreateComponent<UPointLightComponent>(this, &Light2, "Light2", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->TextRenderColor = FColor::Black;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	Light1->Intensity = 1e+4f;
	Light1->AttenuationRadius = 200.0f;
	Light1->LightColor = FColor(255, 128, 50);

	Light2->SetRelativeLocation(FVector(0, 200, 0));
	Light2->Intensity = 1e+4f;
	Light2->AttenuationRadius = 200.0f;
	Light2->LightColor = FColor(255, 128, 50);
}

void AC04_Light::BeginPlay()
{
	Super::BeginPlay();
	
	Light1->SetVisibility(false);
	Light2->SetVisibility(false);

	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC03_Trigger::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	AC03_Trigger* trigger = Cast<AC03_Trigger>(actors[0]);
	trigger->OnBoxBeginOverlap.BindUFunction(this, "OnLight");
	trigger->OnBoxEndOverlap.BindUFunction(this, "OffLight");
	
	trigger->OnBoxRandomOverlap.BindUFunction(this, "OnRandomLight");
}

void AC04_Light::OnLight()
{
	Light1->SetVisibility(true);
}

void AC04_Light::OffLight()
{
	Light1->SetVisibility(false);
	Light2->SetVisibility(false);
}

FString AC04_Light::OnRandomLight(FLinearColor InColor)
{
	Light2->SetVisibility(true);
	Light2->SetLightColor(InColor);

	return InColor.ToString();
}