#include "CDoAction_MagicBall.h"
#include "Global.h"
#include "Components/CStateComponent.h"
#include "Components/CStatusComponent.h"
#include "CAim.h"
#include "GameFramework/Character.h"

void ACDoAction_MagicBall::BeginPlay()
{
	Super::BeginPlay();

	Aim = NewObject<UCAim>();
	Aim->BeginPlay(OwnerCharacter);

}

void ACDoAction_MagicBall::DoAction()
{
	Super::DoAction();

	CheckFalse(State->IsIdleMode());
	State->SetActionMode();

	OwnerCharacter->PlayAnimMontage(Datas[0].AnimMontage, Datas[0].PlayRate, Datas[0].StartSection);
	Datas[0].bCanMove ? Status->SetMove() : Status->SetStop();
}

void ACDoAction_MagicBall::Begin_DoAction()
{
}

void ACDoAction_MagicBall::End_DoAction()
{
	State->SetIdleMode();
	Status->SetMove();
}

void ACDoAction_MagicBall::Tick(float DeltaTime)
{
}

void ACDoAction_MagicBall::OnAim()
{
	Aim->On();
}

void ACDoAction_MagicBall::OffAim()
{
	Aim->Off();
}
