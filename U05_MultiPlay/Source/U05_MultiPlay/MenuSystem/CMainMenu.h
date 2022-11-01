#pragma once

#include "CoreMinimal.h"
#include "IMenuInterface.h"
#include "CMenuWidget.h"
#include "CMainMenu.generated.h"

UCLASS()
class U05_MULTIPLAY_API UCMainMenu : public UCMenuWidget
{
	GENERATED_BODY()

public:
	UCMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FString> InServerNames);
	void SetSelectedIndex(uint32 InIndex);

protected:
	virtual bool Initialize() override;

private:
	UFUNCTION()
		void HostServer();
	
	UFUNCTION()
		void JoinServer();

	UFUNCTION()
		void OpenJoinMenu();

	UFUNCTION()
		void OpenMainMenu();

	UFUNCTION()
		void QuitPressed();

private:
	TSubclassOf<class UUserWidget> ServerRowClass;

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* JoinButton;
	
	UPROPERTY(meta = (BindWidget))
		class UButton* CancelJoinMenuButton;
	
	UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
		class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
		class UPanelWidget* ServerList;

	UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;

private:
	TOptional<uint32> SelectedIndex;
};
