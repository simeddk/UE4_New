#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IRifle.h"
#include "CPlayer.generated.h"

UCLASS()
class U04_RIFLE_API ACPlayer : public ACharacter, public IIRifle
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "Widget")
		TSubclassOf<class UCUserWidget_CrossDot> CrossDotWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widget")
		TSubclassOf<class UCUserWidget_AutoFire> AutoFireWidgetClass;


	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* SpringArm;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		class UCameraComponent* Camera;

protected:
	UFUNCTION(BlueprintImplementableEvent)
		void ZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomOut();

public:
	FORCEINLINE class ACRifle* GetRifle() override { return Rifle; }

	void GetAimRay(FVector& OutAimStart, FVector& OutAimEnd, FVector& OutAimDirection) override;
	void OnFocus() override;
	void OffFocus() override;

public:
	ACPlayer();

	UFUNCTION(BlueprintCallable)
		void SetBodyColor(FLinearColor InBodyColor, FLinearColor InLogoColor);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);

	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);

private:
	void OnRun();
	void OffRun();

	void OnRifle();
	void OnAim();
	void OffAim();
	void OnFire();
	void OffFire();
	void OnAutoFire();


private:
	class UMaterialInstanceDynamic* BodyMaterial;
	class UMaterialInstanceDynamic* LogoMaterial;

private:
	class ACRifle* Rifle;
	class UCUserWidget_CrossDot* CrossDotWidget;
	class UCUserWidget_AutoFire* AutoFireWidget;
};
