#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C08_Event.generated.h"

UCLASS()
class U04_RIFLE_API AC08_Event : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_EVENT_OneParam(AC08_Event, FEventBeginOverlap, int32);

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;
	
public:	
	AC08_Event();

	FEventBeginOverlap OnEventBeginOverlap;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
