#include "CMovingPlatform.h"

ACMovingPlatform::ACMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void ACMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void ACMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector location = GetActorLocation();
		
		FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		FVector direction = (GlobalTargetLocation - location).GetSafeNormal();

		location += direction * Speed * DeltaTime;
		SetActorLocation(location);
	}

}