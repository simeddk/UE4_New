#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C05_ExplosionTrigger.generated.h"

UCLASS()
class U04_RIFLE_API AC05_ExplosionTrigger : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;
	
public:	
	AC05_ExplosionTrigger();

protected:
	virtual void BeginPlay() override;


};
