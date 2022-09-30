#include "C02_DrawDebug.h"
#include "Global.h"

AC02_DrawDebug::AC02_DrawDebug()
{
	PrimaryActorTick.bCanEverTick = true;

	RelativeLocation[0] = FVector(0, 0, 0);
	RelativeLocation[1] = FVector(0, 500, 0);
	RelativeLocation[2] = FVector(-500, 0, 0);
	RelativeLocation[3] = FVector(-1000, 0, 0);
	RelativeLocation[4] = FVector(0, 1000, 0);

	Box = FBox(FVector(-50, -100, -50), FVector(50, 100, 50));
}

void AC02_DrawDebug::BeginPlay()
{
	Super::BeginPlay();
	
	/*DrawDebugBox
	(
		GetWorld(),
		GetActorLocation() + Box.GetCenter(),
		Box.GetExtent(),
		FColor::Red,
		true
	);*/
}

void AC02_DrawDebug::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int32 i = 0; i < 5; i++)
		WorldLocation[i] = GetActorLocation() + RelativeLocation[i];

	DrawDebugSolidBox(GetWorld(), WorldLocation[0] + Box.GetCenter(), Box.GetExtent(), FColor::Red);
	DrawDebugPoint(GetWorld(), WorldLocation[1], 50, FColor::Red);
	DrawDebugSphere(GetWorld(), WorldLocation[2], 100, 30, FColor::Emerald);
	DrawDebugCircle(GetWorld(), WorldLocation[3], 100, 50, FColor::Yellow);

	FVector arrowStart = WorldLocation[1];
	FVector arrowEnd = WorldLocation[3];
	DrawDebugDirectionalArrow(GetWorld(), arrowStart, arrowEnd, 400, FColor::Green, false, -1.f, 0, 10.f);

	FVector sinLocation = WorldLocation[2];
	sinLocation.X += sin(GetWorld()->GetTimeSeconds() * 3.f) * 300.f;
	
	DrawDebugPoint(GetWorld(), sinLocation, 50, FColor::Red);
}

