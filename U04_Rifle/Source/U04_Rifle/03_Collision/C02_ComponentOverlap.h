#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_ComponentOverlap.generated.h"

UCLASS()
class U04_RIFLE_API AC02_ComponentOverlap : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleAnywhere)
		class UPointLightComponent* Light;
	
public:	
	AC02_ComponentOverlap();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
