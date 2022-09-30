#include "C01_Log.h"
#include "Global.h"

AC01_Log::AC01_Log()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AC01_Log::BeginPlay()
{
	Super::BeginPlay();

	Number = 10;
	
	CLog::Print(1);
	CLog::Print(2, 1);
	CLog::Print(3, 2, 20.f);
	CLog::Print(4, 2, 20.f, FColor::Blue);
	CLog::Print("Test");
	CLog::Print(GetActorLocation());
	CLog::Print(GetActorRotation());

	Number = 20;

	CLog::Log(20);
	CLog::Log(PI);
	CLog::Log("Log Test!");
	CLog::Log(GetActorLocation());
	CLog::Log(GetActorRotation());
	CLog::Log(this);
	CLog::Log(__FILE__);
	//CLog::Log(__FUNCTION__, __LINE__);
	PrintLine();

	CLog::Log(Number);

	Number = 30;
}

void AC01_Log::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	CLog::Print(RunningTime, 7);
}

