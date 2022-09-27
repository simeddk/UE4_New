#include "C01_Property.h"

AC01_Property::AC01_Property()
{
	PrimaryActorTick.bCanEverTick = true;

	C = 30;
}

void AC01_Property::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC01_Property::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

