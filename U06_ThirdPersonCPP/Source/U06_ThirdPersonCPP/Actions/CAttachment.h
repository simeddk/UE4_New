#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CAttachment.generated.h"

UCLASS()
class U06_THIRDPERSONCPP_API ACAttachment : public AActor
{
	GENERATED_BODY()
	
public:	
	ACAttachment();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
		void AttachTo(FName InSocketName);

	UFUNCTION(BlueprintImplementableEvent)
		void OnEquip();

	UFUNCTION(BlueprintImplementableEvent)
		void OnUnequip();

protected:
	UPROPERTY(BlueprintReadOnly)
		class ACharacter* OwnerCharacter;

	UPROPERTY(BlueprintReadOnly)
		class UCStateComponent* State;

	UPROPERTY(BlueprintReadOnly)
		class UCStatusComponent* Status;

};
