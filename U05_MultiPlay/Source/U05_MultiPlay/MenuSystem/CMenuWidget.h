#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IMenuInterface.h"
#include "CMenuWidget.generated.h"

UCLASS()
class U05_MULTIPLAY_API UCMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IIMenuInterface* InMenuInterface);
	void Setup();
	void Teardown();
	
protected:
	IIMenuInterface* MenuInterface;
};
