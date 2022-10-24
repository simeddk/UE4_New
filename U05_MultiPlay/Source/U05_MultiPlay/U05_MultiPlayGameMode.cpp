// Copyright Epic Games, Inc. All Rights Reserved.

#include "U05_MultiPlayGameMode.h"
#include "U05_MultiPlayCharacter.h"
#include "UObject/ConstructorHelpers.h"

AU05_MultiPlayGameMode::AU05_MultiPlayGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
