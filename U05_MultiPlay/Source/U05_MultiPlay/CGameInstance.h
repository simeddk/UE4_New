#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/IMenuInterface.h"
#include "CGameInstance.generated.h"

UCLASS()
class U05_MULTIPLAY_API UCGameInstance : public UGameInstance, public IIMenuInterface
{
	GENERATED_BODY()
	
public:
	UCGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init() override;

public:
	UFUNCTION(Exec)
		void Host() override;

	UFUNCTION(Exec)
		void Join(const FString& InAddress) override;

	UFUNCTION(BlueprintCallable, Exec)
		void LoadMenu();

private:
	TSubclassOf<class UUserWidget> MenuClass;

	class UCMainMenu* Menu;
};
