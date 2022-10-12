#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_LineTrace.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLineTraceEvent, class AActor*, InActor, FLinearColor, InColor);

UCLASS()
class U04_RIFLE_API AC02_LineTrace : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;

public:	
	AC02_LineTrace();

	
	UFUNCTION(BlueprintCallable)
		void ResetPlayerColor(class ACPlayer* InPlayer);

private:
	UFUNCTION()
		void Ragdoll(class AActor* InActor, FLinearColor InColor);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(BlueprintAssignable)
		FLineTraceEvent OnLineTraceEvent;

private:
	class AC01_Point* Points[2];

};
