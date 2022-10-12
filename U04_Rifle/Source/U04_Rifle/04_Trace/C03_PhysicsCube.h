#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C03_PhysicsCube.generated.h"

UCLASS()
class U04_RIFLE_API AC03_PhysicsCube : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

public:	
	AC03_PhysicsCube();

protected:
	virtual void BeginPlay() override;


};
