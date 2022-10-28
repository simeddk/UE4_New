#include "CMenuWidget.h"

void UCMenuWidget::SetMenuInterface(IIMenuInterface* InMenuInterface)
{
	MenuInterface = InMenuInterface;
}

void UCMenuWidget::Setup()
{
	this->AddToViewport();
	this->bIsFocusable = true;

	FInputModeUIOnly inputMode;
	inputMode.SetWidgetToFocus(this->TakeWidget());
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	UWorld* world = GetWorld();
	if (world == nullptr) return;

	APlayerController* playerController = world->GetFirstPlayerController();
	playerController->SetInputMode(inputMode);
	playerController->bShowMouseCursor = true;
}

void UCMenuWidget::Teardown()
{
	this->RemoveFromViewport();
	this->bIsFocusable = false;

	FInputModeGameOnly inputMode;

	UWorld* world = GetWorld();
	if (world == nullptr) return;

	APlayerController* playerController = world->GetFirstPlayerController();
	playerController->SetInputMode(inputMode);
	playerController->bShowMouseCursor = false;
}

