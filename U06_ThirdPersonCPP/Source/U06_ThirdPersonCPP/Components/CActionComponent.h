#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CActionComponent.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
	Unaremd, Fist, OneHand, TwoHand, MagicBall, Warp, MagicStorm, Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActionTypeChanged, EActionType, InPrevType, EActionType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class U06_THIRDPERSONCPP_API UCActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCActionComponent();

private:
	UPROPERTY(EditDefaultsOnly)
		class UCActionData* Datas[(int32)EActionType::Max];

public:
	UFUNCTION(BlueprintPure)
		FORCEINLINE class UCActionData* GetCurrent() { return Datas[(int32)Type]; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsUnarmedMode() { return Type == EActionType::Unaremd; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsFistMode() { return Type == EActionType::Fist; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsOneHandMode() { return Type == EActionType::OneHand; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsTwoHandMode() { return Type == EActionType::TwoHand; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsMagicBallMode() { return Type == EActionType::MagicBall; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsWarpMode() { return Type == EActionType::Warp; }

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsMagicStormMode() { return Type == EActionType::MagicStorm; }

public:
	void SetUnarmedMode();
	void SetFistMode();
	void SetOneHandMode();
	void SetTwoHandMode();
	void SetMagicBallMode();
	void SetWarpMode();
	void SetMagicStormMode();

private:
	void SetMode(EActionType InNewType);
	void ChangeType(EActionType InNewType);

public:
	void DoAction();

	void DoOnAim();
	void DoOffAim();


	void Dead();
	void End_Dead();

	void OffAllCollisios();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
		FActionTypeChanged OnActionTypeChanged;

private:
	EActionType Type;
};
