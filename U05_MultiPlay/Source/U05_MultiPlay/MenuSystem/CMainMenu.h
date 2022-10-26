#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CMainMenu.generated.h"

UCLASS()
class U05_MULTIPLAY_API UCMainMenu : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	virtual bool Initialize() override;

private:
	UFUNCTION()
		void HostServer();

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* Host;

	UPROPERTY(meta = (BindWidget))
		class UButton* Join;
};
