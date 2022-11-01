#include "CGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h" 
#include "Blueprint/UserWidget.h"
#include "MenuSystem/CMainMenu.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"

const static FName SESSION_NAME = TEXT("GameSession");

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
	IOnlineSubsystem* subsystem = IOnlineSubsystem::Get();
	if (!!subsystem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Subsystem found. Name : %s"), *subsystem->GetSubsystemName().ToString());
		
		SessionInterface = subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Session Interface Found"));
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UCGameInstance::OnCreateSessionCompleted);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UCGameInstance::OnDestroySessionCompleted);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UCGameInstance::OnFindSessionCompleted);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Found Subsystem"));
	}
}

void UCGameInstance::Host()
{
	if (SessionInterface.IsValid())
	{
		auto exsistingSession = SessionInterface->GetNamedSession(SESSION_NAME);

		if (!!exsistingSession)
		{
			SessionInterface->DestroySession(SESSION_NAME);
		}
		else
		{
			CreateSession();
		}
		
	}
}

void UCGameInstance::Join(const FString& InAddress)
{
	/*if (!!Menu)
		Menu->Teardown();
	 
	UEngine* engine = GetEngine();
	if (engine == nullptr) return;
	engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Join to %s"), *InAddress));
	
	APlayerController* controller = GetFirstLocalPlayerController();
	if (controller == nullptr) return;
	controller->ClientTravel(InAddress, ETravelType::TRAVEL_Absolute);*/

	if (!!Menu)
		Menu->SetServerList({"Lobby1", "Lobby2"});
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

void UCGameInstance::RefreshServerList()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (SessionSearch.IsValid())
	{
		//SessionSearch->bIsLanQuery = true;
		UE_LOG(LogTemp, Warning, TEXT("Starting Find Session"));
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
}

void UCGameInstance::OnCreateSessionCompleted(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not create session!!"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Session Name : %s"), *SessionName.ToString());

	if (!!Menu)
		Menu->Teardown();

	UEngine* engine = GetEngine();
	if (engine == nullptr) return;
	engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Host"));

	UWorld* world = GetWorld();
	if (world == nullptr) return;
	world->ServerTravel("/Game/Maps/Play?listen");
}

void UCGameInstance::OnDestroySessionCompleted(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful == true)
		CreateSession();
}

void UCGameInstance::OnFindSessionCompleted(bool bWasSuccessful)
{
	if (bWasSuccessful == true && SessionSearch.IsValid() && Menu != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Finished Find Session"));
		
		TArray<FString> serverNames;
		for (const FOnlineSessionSearchResult& searchResult : SessionSearch->SearchResults)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found Session ID : %s"), *searchResult.GetSessionIdStr());
			UE_LOG(LogTemp, Warning, TEXT("Ping : %d"), searchResult.PingInMs);

			serverNames.Add(searchResult.GetSessionIdStr());
		}

		Menu->SetServerList(serverNames);
	}
}

void UCGameInstance::CreateSession()
{
	if (SessionInterface.IsValid())
	{
		FOnlineSessionSettings sessionSettings;
		sessionSettings.bIsLANMatch = true;
		sessionSettings.NumPublicConnections = 2;
		sessionSettings.bShouldAdvertise = true;

		SessionInterface->CreateSession(0, SESSION_NAME, sessionSettings);
	}
}
