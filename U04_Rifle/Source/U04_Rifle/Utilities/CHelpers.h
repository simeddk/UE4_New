#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"

class U04_RIFLE_API CHelpers
{
public:
	template<typename T>
	static void GetAsset(T** OutObject, FString InPath)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), L"Asset Not Found");

		*OutObject = asset.Object;
	}

};