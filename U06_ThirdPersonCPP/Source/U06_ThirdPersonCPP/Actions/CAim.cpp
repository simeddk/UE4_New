#include "CAim.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

UCAim::UCAim()
{

}

void UCAim::BeginPlay(ACharacter* InOwnerCharacter)
{
	OwnerCharacter = InOwnerCharacter;

	SpringArm = CHelpers::GetComponent<USpringArmComponent>(OwnerCharacter);
	Camera = CHelpers::GetComponent<UCameraComponent>(OwnerCharacter);
}

void UCAim::Tick(float DeltaTime)
{

}

void UCAim::On()
{
	CheckFalse(IsAvaliable());
	CheckTrue(bZooming);

	bZooming = true;

	SpringArm->TargetArmLength = 100.f;
	SpringArm->SocketOffset = FVector(0, 30, 10);
	SpringArm->bEnableCameraLag = false;

	Camera->FieldOfView = 45;
}

void UCAim::Off()
{
	CheckFalse(IsAvaliable());
	CheckFalse(bZooming);

	bZooming = false;

	SpringArm->TargetArmLength = 200.f;
	SpringArm->SocketOffset = FVector(0, 0, 0);
	SpringArm->bEnableCameraLag = true;

	Camera->FieldOfView = 90;
}
