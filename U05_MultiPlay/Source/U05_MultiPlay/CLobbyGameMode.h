#pragma once

#include "CoreMinimal.h"
#include "U05_MultiPlayGameMode.h"
#include "CLobbyGameMode.generated.h"

UCLASS()
class U05_MULTIPLAY_API ACLobbyGameMode : public AU05_MultiPlayGameMode
{
	GENERATED_BODY()

public:
	void PostLogin(APlayerController* NewPlayer) override;
	void Logout(AController* Exiting) override;

private:
	void StartGame();

private:
	uint32 NumberOfPlayers;
	FTimerHandle GameStartTimer;
};
