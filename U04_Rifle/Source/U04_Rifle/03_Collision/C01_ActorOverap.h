#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_ActorOverap.generated.h"

UCLASS()
class U04_RIFLE_API AC01_ActorOverap : public AActor
{
	GENERATED_BODY()
	
public:	
	AC01_ActorOverap();

protected:
	virtual void BeginPlay() override;


};
