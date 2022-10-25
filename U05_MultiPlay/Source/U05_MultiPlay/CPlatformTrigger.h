#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPlatformTrigger.generated.h"

UCLASS()
class U05_MULTIPLAY_API ACPlatformTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	ACPlatformTrigger();

protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Box;

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UPROPERTY(EditAnywhere)
		TArray<class ACMovingPlatform*> PlatformsToTrigger;
};
