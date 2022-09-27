#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_MeshActor.generated.h"

UCLASS()
class U04_RIFLE_API AC02_MeshActor : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly)
		UStaticMeshComponent* Mesh;
	
public:	
	AC02_MeshActor();

protected:
	virtual void BeginPlay() override;


};
