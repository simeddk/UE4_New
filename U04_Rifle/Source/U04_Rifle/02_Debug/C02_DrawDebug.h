#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_DrawDebug.generated.h"

UCLASS()
class U04_RIFLE_API AC02_DrawDebug : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FVector RelativeLocation[5];

	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FBox Box;
	
public:	
	AC02_DrawDebug();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	FVector WorldLocation[5];

};
