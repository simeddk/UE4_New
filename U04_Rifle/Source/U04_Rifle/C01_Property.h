#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_Property.generated.h"

UCLASS()
class U04_RIFLE_API AC01_Property : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		int A = 10;

	UPROPERTY(EditInstanceOnly)
		int B = 20;

	UPROPERTY(EditDefaultsOnly)
		int C;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int Test = 40;
	
public:	
	AC01_Property();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;



};
