#include "C10_BlueprintEvent.h"
#include "Global.h"
#include "CPlayer.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

AC10_BlueprintEvent::AC10_BlueprintEvent()
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

void AC10_BlueprintEvent::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &AC10_BlueprintEvent::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &AC10_BlueprintEvent::ActorEndOverlap);
}


void AC10_BlueprintEvent::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ChangePlayerColor();
}

void AC10_BlueprintEvent::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ResetPlayerColor();
}


void AC10_BlueprintEvent::ResetPlayerColor_Implementation()
{
	ACPlayer* player = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->SetBodyColor(FLinearColor(0.450980f, 0.403922f, 0.360784f), FLinearColor(0.450980f, 0.403922f, 0.360784f));
}