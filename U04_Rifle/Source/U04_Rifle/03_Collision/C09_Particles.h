#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C09_Particles.generated.h"

UCLASS()
class U04_RIFLE_API AC09_Particles : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleAnywhere)
		class UParticleSystem* Particles[3];
	
public:	
	AC09_Particles();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void PlayParticle(int32 InIndex);
};
