#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C07_SpotLights.generated.h"

UCLASS()
class U04_RIFLE_API AC07_SpotLights : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleAnywhere)
		class USpotLightComponent* SpotLights[3];
	
public:	
	AC07_SpotLights();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnLightColor(int32 InIndex, FLinearColor InColor);

};
