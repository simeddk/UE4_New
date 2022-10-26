#include "CGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h" 
#include "Blueprint/UserWidget.h"


UCGameInstance::UCGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor!!"));

	ConstructorHelpers::FClassFinder<UUserWidget> menuBPClass(TEXT("WidgetBlueprint'/Game/Widgets/WB_MainMenu.WB_MainMenu_C'"));
	if (menuBPClass.Succeeded())
		MenuClass = menuBPClass.Class;
}

void UCGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init!!"));

	
}

void UCGameInstance::Host()
{
	UEngine* engine = GetEngine();
	if (engine == nullptr) return;
	engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Host"));

	UWorld* world = GetWorld();
	if (world == nullptr) return;
	world->ServerTravel("/Game/Maps/Play?listen");
}

void UCGameInstance::Join(const FString& InAddress)
{
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

	UUserWidget* menu = CreateWidget<UUserWidget>(this, MenuClass);
	if (menu == nullptr) return;

	menu->AddToViewport();

	menu->bIsFocusable = true;

	FInputModeUIOnly inputMode;
	inputMode.SetWidgetToFocus(menu->TakeWidget());
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	APlayerController* playerController = GetFirstLocalPlayerController();
	playerController->SetInputMode(inputMode);
	playerController->bShowMouseCursor = true;
}
