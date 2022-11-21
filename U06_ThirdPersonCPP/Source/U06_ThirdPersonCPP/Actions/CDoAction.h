#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CActionData.h"
#include "CDoAction.generated.h"

UCLASS()
class U06_THIRDPERSONCPP_API ACDoAction : public AActor
{
	GENERATED_BODY()
	
public:	
	ACDoAction();

	FORCEINLINE void SetDatas(TArray<FDoActionData> InDatas) { Datas = InDatas; }

public:
	virtual void DoAction() {};
	virtual void Begin_DoAction() {};
	virtual void End_DoAction() {};

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadOnly)
		class ACharacter* OwnerCharacter;

	UPROPERTY(BlueprintReadOnly)
		class UCStateComponent* State;

	UPROPERTY(BlueprintReadOnly)
		class UCStatusComponent* Status;


protected:
	TArray<FDoActionData> Datas;
};
