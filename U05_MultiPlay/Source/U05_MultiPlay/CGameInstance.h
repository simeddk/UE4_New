#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CGameInstance.generated.h"

UCLASS()
class U05_MULTIPLAY_API UCGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UCGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init() override;

public:
	UFUNCTION(Exec)
		void Host();

	UFUNCTION(Exec)
		void Join(const FString& InAddress);
};
