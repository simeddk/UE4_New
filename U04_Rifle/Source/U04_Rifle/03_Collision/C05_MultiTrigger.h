#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C05_MultiTrigger.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiBeginOverlap, int32, FLinearColor);

UCLASS()
class U04_RIFLE_API AC05_MultiTrigger : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;
	
public:	
	AC05_MultiTrigger();

	FMultiBeginOverlap OnMultiBeginOverlap;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
