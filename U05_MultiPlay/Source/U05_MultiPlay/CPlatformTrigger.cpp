#include "CPlatformTrigger.h"
#include "CMovingPlatform.h"
#include "Components/BoxComponent.h"

ACPlatformTrigger::ACPlatformTrigger()
{
	Box = CreateDefaultSubobject<UBoxComponent>(FName("Box"));
	if (Box == nullptr) return;

	RootComponent = Box;
}

void ACPlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	Box->OnComponentBeginOverlap.AddDynamic(this, &ACPlatformTrigger::OnBeginOverlap);
	Box->OnComponentEndOverlap.AddDynamic(this, &ACPlatformTrigger::OnEndOverlap);
}

void ACPlatformTrigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (ACMovingPlatform* platform : PlatformsToTrigger)
		platform->AddActiveTrigger();
}

void ACPlatformTrigger::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	for (ACMovingPlatform* platform : PlatformsToTrigger)
		platform->RemoveActiveTrigger();
}

