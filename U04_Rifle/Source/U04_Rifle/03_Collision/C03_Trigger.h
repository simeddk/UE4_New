#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C03_Trigger.generated.h"

DECLARE_DELEGATE(FBoxBeginOverlap);
DECLARE_DELEGATE(FBoxEndOverlap);

UCLASS()
class U04_RIFLE_API AC03_Trigger : public AActor
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
	AC03_Trigger();

	FBoxBeginOverlap OnBoxBeginOverlap;
	FBoxEndOverlap OnBoxEndOverlap;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
