#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C06_Cubes.generated.h"

UCLASS()
class U04_RIFLE_API AC06_Cubes : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* Meshes[3];
	
public:	
	AC06_Cubes();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnDropAndChangeColor(int32 InIndex, FLinearColor InColor);

private:
	class UMaterialInstanceDynamic* Materials[3];
	FVector FirstLocations[3];
};
