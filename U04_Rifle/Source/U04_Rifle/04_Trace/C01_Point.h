#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_Point.generated.h"

UCLASS()
class U04_RIFLE_API AC01_Point : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;
	
public:	
	AC01_Point();

protected:
	virtual void BeginPlay() override;


};
