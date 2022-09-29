#include "C03_Spawner.h"
#include "Global.h"
#include "C02_MeshActor.h"

AC03_Spawner::AC03_Spawner()
{
	

}

void AC03_Spawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < 4; i++)
	{
		FTransform transform;

		SpawnActors[i] = GetWorld()->SpawnActor<AC02_MeshActor>(SpawnSubClasses[i], transform);

		FVector location = GetActorLocation();
		SpawnActors[i]->SetActorLocation(FVector(location.X, location.Y + i * 200, location.Z));
	}
}

