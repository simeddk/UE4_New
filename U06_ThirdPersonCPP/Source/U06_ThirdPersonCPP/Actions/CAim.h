#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CAim.generated.h"

UCLASS()
class U06_THIRDPERSONCPP_API UCAim : public UObject
{
	GENERATED_BODY()

public:
	UCAim();

	FORCEINLINE bool IsAvaliable() { return SpringArm != nullptr && Camera != nullptr; }

public:
	void BeginPlay(class ACharacter* InOwnerCharacter);
	void Tick(float DeltaTime);
	
	void On();
	void Off();

private:
	class ACharacter* OwnerCharacter;
	class USpringArmComponent* SpringArm;
	class UCameraComponent* Camera;

	bool bZooming;
};
