#include "CMainMenu.h"
#include "CServerRow.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"

UCMainMenu::UCMainMenu(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> serverRowClass(TEXT("/Game/Widgets/WB_ServerRow"));
	if (serverRowClass.Succeeded())
		ServerRowClass = serverRowClass.Class;
}

bool UCMainMenu::Initialize()
{
	bool success = Super::Initialize();
	if (success == false) return false;

	if (HostButton == nullptr) return false;
	HostButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenHostMenu);

	if (CancelHostMenuButton == nullptr) return false;
	CancelHostMenuButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenMainMenu);

	if (ConfirmHostMenuButton == nullptr) return false;
	ConfirmHostMenuButton->OnClicked.AddDynamic(this, &UCMainMenu::HostServer);

	if (JoinButton == nullptr) return false;
	JoinButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenJoinMenu);

	if (CancelJoinMenuButton == nullptr) return false;
	CancelJoinMenuButton->OnClicked.AddDynamic(this, &UCMainMenu::OpenMainMenu);

	if (ConfirmJoinMenuButton == nullptr) return false;
	ConfirmJoinMenuButton->OnClicked.AddDynamic(this, &UCMainMenu::JoinServer);

	if (QuitButton == nullptr) return false;
	QuitButton->OnClicked.AddDynamic(this, &UCMainMenu::QuitPressed);

	return true;
}

void UCMainMenu::HostServer()
{
	if (!!MenuInterface)
	{
		FString serverName = ServerHostName->Text.ToString();
		MenuInterface->Host(serverName);
	}
}

void UCMainMenu::SetServerList(TArray<FServerData> InServerDatas)
{
	UWorld* world = GetWorld();
	if (world == nullptr) return;

	ServerList->ClearChildren();

	uint32 i = 0;
	for (const FServerData& serverData : InServerDatas)
	{
		UCServerRow* row = CreateWidget<UCServerRow>(world, ServerRowClass);
		if (row == nullptr) return;

		row->ServerName->SetText(FText::FromString(serverData.Name));
		row->HostUser->SetText(FText::FromString(serverData.HostUserName));
		FString fractionText = FString::Printf(TEXT("%d/%d"), serverData.CurrentPlayers, serverData.MaxPlayers);
		row->ConnectedFraction->SetText(FText::FromString(fractionText));

		row->SetUp(this, i++);

		ServerList->AddChild(row);
	}

}

void UCMainMenu::SetSelectedIndex(uint32 InIndex)
{
	SelectedIndex = InIndex;
	SelectServerRow();
}

void UCMainMenu::JoinServer()
{
	if (SelectedIndex.IsSet() && !!MenuInterface)
	{
		UE_LOG(LogTemp, Warning, TEXT("SelectedIndex : %d"), SelectedIndex.GetValue());
		MenuInterface->Join(SelectedIndex.GetValue());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SelectedIndex is not set"));
	}
}

void UCMainMenu::OpenJoinMenu()
{
	if (MenuSwitcher == nullptr) return;
	if (JoinMenu == nullptr) return;

	if (MenuInterface != nullptr)
	{
		MenuInterface->RefreshServerList();
	}

	MenuSwitcher->SetActiveWidget(JoinMenu);
}


void UCMainMenu::OpenHostMenu()
{
	if (MenuSwitcher == nullptr) return;
	if (HostMenu == nullptr) return;
	MenuSwitcher->SetActiveWidget(HostMenu);
}

void UCMainMenu::OpenMainMenu()
{
	if (MenuSwitcher == nullptr) return;
	if (MainMenu == nullptr) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UCMainMenu::QuitPressed()
{
	UWorld* world = GetWorld();
	if (world == nullptr) return;

	APlayerController* controller = world->GetFirstPlayerController();
	if (controller == nullptr) return;

	controller->ConsoleCommand("Quit");
}

void UCMainMenu::SelectServerRow()
{
	for (int32 i = 0; i < ServerList->GetChildrenCount(); i++)
	{
		UCServerRow* serverRow = Cast<UCServerRow>(ServerList->GetChildAt(i));
		if (!!serverRow)
			serverRow->Selected = (SelectedIndex.IsSet() && i == SelectedIndex.GetValue());
	}
}
