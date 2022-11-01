#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/IMenuInterface.h"
#include "OnlineSubSystem.h"
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

	UFUNCTION(BlueprintCallable)
		void InGameLoadMenu();

	virtual void LoadMainMenu() override;
	void RefreshServerList() override;

private:
	void OnCreateSessionCompleted(FName SessionName, bool bWasSuccessful);
	void OnDestroySessionCompleted(FName SessionName, bool bWasSuccessful);
	void OnFindSessionCompleted(bool bWasSuccessful);

	void CreateSession();

private:
	TSubclassOf<class UUserWidget> MenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UCMainMenu* Menu;

	IOnlineSessionPtr SessionInterface;
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;
};
