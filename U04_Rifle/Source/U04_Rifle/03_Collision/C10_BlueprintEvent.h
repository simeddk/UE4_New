#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C10_BlueprintEvent.generated.h"

UCLASS()
class U04_RIFLE_API AC10_BlueprintEvent : public AActor
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
	AC10_BlueprintEvent();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
		void ChangePlayerColor();

	UFUNCTION(BlueprintNativeEvent)
		void ResetPlayerColor();
	void ResetPlayerColor_Implementation();

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
