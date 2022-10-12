#include "C02_LineTrace.h"
#include "Global.h"
#include "CPlayer.h"
#include "C01_Point.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"

AC02_LineTrace::AC02_LineTrace()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->TextRenderColor = FColor::Black;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());
}



void AC02_LineTrace::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC01_Point::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	Points[0] = Cast<AC01_Point>(actors[0]);
	Points[1] = Cast<AC01_Point>(actors[1]);

	OnLineTraceEvent.AddDynamic(this, &AC02_LineTrace::Ragdoll);
}

void AC02_LineTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector start = Points[0]->GetActorLocation();
	FVector end = Points[1]->GetActorLocation();

	//DebugLine
	{
		start.Z -= 20;
		end.Z -= 20;

		//DrawDebugLine(GetWorld(), start, end, FColor::Red);
	}

	//LineTrace
	{
		TArray<AActor*> ignores;
		ignores.Add(Points[0]);
		ignores.Add(Points[1]);

		FHitResult hitResult;

		if (UKismetSystemLibrary::LineTraceSingleByProfile
		(
			GetWorld(),
			start,
			end,
			"Pawn",
			true, 
			ignores,
			EDrawDebugTrace::ForOneFrame,
			hitResult,
			true,
			FLinearColor::Blue,
			FLinearColor::Red
		))
		{
			FLinearColor color = FLinearColor::MakeRandomColor();
			color.A = 1.0f;

			OnLineTraceEvent.Broadcast(hitResult.GetActor(), color);
		}
	}
}

void AC02_LineTrace::ResetPlayerColor(ACPlayer* InPlayer)
{
	CheckNull(InPlayer);
	InPlayer->SetBodyColor(FLinearColor(1, 1, 1), FLinearColor(1, 1, 1));
}

void AC02_LineTrace::Ragdoll(AActor* InActor, FLinearColor InColor)
{
	ACPlayer* player = Cast<ACPlayer>(InActor);
	CheckNull(player);

	player->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	player->GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	player->GetMesh()->SetSimulatePhysics(true);
	player->GetMesh()->AddImpulse(FVector(1e+5f, 0.f, 1e+5f));
	player->GetMesh()->GlobalAnimRateScale = 0.f;

	Text->SetText("+_+");
	Text->SetTextRenderColor(FColor::Red);
}
