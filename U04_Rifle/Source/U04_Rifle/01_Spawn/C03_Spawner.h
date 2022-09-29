#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C03_Spawner.generated.h"

UCLASS()
class U04_RIFLE_API AC03_Spawner : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
		UClass* SpawnClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_MeshActor> SpawnSubClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_MeshActor> SpawnSubClasses[4];
	
public:	
	AC03_Spawner();

protected:
	virtual void BeginPlay() override;

private:
	class AC02_MeshActor* SpawnActors[4];
};
