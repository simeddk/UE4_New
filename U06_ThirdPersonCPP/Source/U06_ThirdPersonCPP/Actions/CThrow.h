#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CThrow.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FThrowBeginOverlap, FHitResult, InHitResult);

UCLASS()
class U06_THIRDPERSONCPP_API ACThrow : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
		class UParticleSystem* ImpactParticle;

	UPROPERTY(EditDefaultsOnly)
		FTransform ImpactParticleTransform;

	UPROPERTY(EditDefaultsOnly)
		class USphereComponent* Sphere;

	UPROPERTY(EditDefaultsOnly)
		class UParticleSystemComponent* ThrowParticle;

	UPROPERTY(EditDefaultsOnly)
		class UProjectileMovementComponent* Projectile;
	
public:	
	ACThrow();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:
	UPROPERTY(BlueprintAssignable)
		FThrowBeginOverlap OnThrowBeginOverlap;
};
