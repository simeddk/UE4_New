#include "C02_ComponentOverlap.h"
#include "Global.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/PointLightComponent.h"

AC02_ComponentOverlap::AC02_ComponentOverlap()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UBoxComponent>(this, &Box, "Box", Scene);
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	CHelpers::CreateComponent<UPointLightComponent>(this, &Light, "Light", Scene);

	Box->bHiddenInGame = false;
	Box->SetRelativeScale3D(FVector(3));

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->TextRenderColor = FColor::Black;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());

	Light->SetLightColor(FLinearColor::Red);
}

void AC02_ComponentOverlap::BeginPlay()
{
	Super::BeginPlay();
	
	Box->OnComponentBeginOverlap.AddDynamic(this, &AC02_ComponentOverlap::ComponentBeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &AC02_ComponentOverlap::ComponentEndOverlap);
	Light->SetVisibility(false);
}

void AC02_ComponentOverlap::ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Light->SetVisibility(true);
}

void AC02_ComponentOverlap::ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Light->SetVisibility(false);
}

