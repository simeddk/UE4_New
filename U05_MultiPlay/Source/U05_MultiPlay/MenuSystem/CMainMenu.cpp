#include "CMainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

bool UCMainMenu::Initialize()
{
	bool success = Super::Initialize();
	if (success == false) return false;

	if (HostButton == nullptr) return false;
	HostButton->OnClicked.AddDynamic(this, &UCMainMenu::HostServer);

	if (JoinButton == nullptr) return false;
	JoinButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenJoinMenu);

	if (CancelJoinMenuButton == nullptr) return false;
	CancelJoinMenuButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenMainMenu);

	if (ConfirmJoinMenuButton == nullptr) return false;
	ConfirmJoinMenuButton->OnClicked.AddDynamic(this, &UCMainMenu::JoinServer);

	return true;
}

void UCMainMenu::HostServer()
{
	if (!!MenuInterface)
		MenuInterface->Host();
}

void UCMainMenu::JoinServer()
{
	if (!!MenuInterface)
	{
		if (IPAddressFeild == nullptr) return;
		const FString& address = IPAddressFeild->GetText().ToString();
		MenuInterface->Join(address);
	}
}

void UCMainMenu::OpenJoinMenu()
{
	if (MenuSwitcher == nullptr) return;
	if (JoinMenu == nullptr) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UCMainMenu::OpenMainMenu()
{
	if (MenuSwitcher == nullptr) return;
	if (MainMenu == nullptr) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UCMainMenu::SetMenuInterface(IIMenuInterface* InMenuInterface)
{
	MenuInterface = InMenuInterface;
}

void UCMainMenu::Setup()
{
	this->AddToViewport();

	this->bIsFocusable = true;

	FInputModeUIOnly inputMode;
	inputMode.SetWidgetToFocus(this->TakeWidget());
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	UWorld* world =  GetWorld();
	if (world == nullptr) return;

	APlayerController* playerController = world->GetFirstPlayerController();
	playerController->SetInputMode(inputMode);
	playerController->bShowMouseCursor = true;
}

void UCMainMenu::Teardown()
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