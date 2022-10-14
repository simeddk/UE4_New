#include "CAnimNotifyState_Unequip.h"
#include "Global.h"
#include "IRifle.h"
#include "CRifle.h"

FString UCAnimNotifyState_Unequip::GetNotifyName_Implementation() const
{
	return "Unequip";
}

void UCAnimNotifyState_Unequip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	IIRifle* rifleCharacter = Cast<IIRifle>(MeshComp->GetOwner());
	CheckNull(rifleCharacter);

	rifleCharacter->GetRifle()->Begin_Unequip();
}

void UCAnimNotifyState_Unequip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);

	IIRifle* rifleCharacter = Cast<IIRifle>(MeshComp->GetOwner());
	CheckNull(rifleCharacter);

	rifleCharacter->GetRifle()->End_Unequip();
}