#include "CGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h" 
#include "Blueprint/UserWidget.h"
#include "MenuSystem/CMainMenu.h"

UCGameInstance::UCGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> menuBPClass(TEXT("/Game/Widgets/WB_MainMenu"));
	if (menuBPClass.Succeeded())
		MenuClass = menuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> inGameMenuBPClass(TEXT("/Game/Widgets/WB_InGameMenu"));
	if (inGameMenuBPClass.Succeeded())
		InGameMenuClass = inGameMenuBPClass.Class;
}

void UCGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init!!"));
}

void UCGameInstance::Host()
{
	if (!!Menu)
		Menu->Teardown();

	UEngine* engine = GetEngine();
	if (engine == nullptr) return;
	engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Host"));

	UWorld* world = GetWorld();
	if (world == nullptr) return;
	world->ServerTravel("/Game/Maps/Play?listen");
}

void UCGameInstance::Join(const FString& InAddress)
{
	if (!!Menu)
		Menu->Teardown();

	UEngine* engine = GetEngine();
	if (engine == nullptr) return;
	engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Join to %s"), *InAddress));

	APlayerController* controller = GetFirstLocalPlayerController();
	if (controller == nullptr) return;
	controller->ClientTravel(InAddress, ETravelType::TRAVEL_Absolute);
}

void UCGameInstance::LoadMenu()
{
	if (MenuClass == nullptr) return;

	Menu = CreateWidget<UCMainMenu>(this, MenuClass);
	if (Menu == nullptr) return;
	Menu->SetMenuInterface(this);
	Menu->Setup();
}

void UCGameInstance::InGameLoadMenu()
{
	if (InGameMenuClass == nullptr) return;

	UCMenuWidget* inGameMenu = CreateWidget<UCMenuWidget>(this, InGameMenuClass);
	if (inGameMenu == nullptr) return;
	inGameMenu->SetMenuInterface(this);
	inGameMenu->Setup();
}

void UCGameInstance::LoadMainMenu()
{
	APlayerController* controller = GetFirstLocalPlayerController();
	if (controller == nullptr) return;
	controller->ClientTravel("/Game/Maps/MainMenu", ETravelType::TRAVEL_Absolute);
}
