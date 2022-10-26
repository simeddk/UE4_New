#include "CMainMenu.h"
#include "Components/Button.h"

bool UCMainMenu::Initialize()
{
	bool success = Super::Initialize();
	if (success == false) return false;

	if (Host == nullptr) return false;
	Host->OnClicked.AddDynamic(this, &UCMainMenu::HostServer);

	return true;
}

void UCMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Button Clicked"));
}
