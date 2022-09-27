#include "C02_MeshActor.h"

AC02_MeshActor::AC02_MeshActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/StaticMeshes/SM_Cone.SM_Cone'");

	if (mesh.Succeeded())
		Mesh->SetStaticMesh(mesh.Object);

}

void AC02_MeshActor::BeginPlay()
{
	Super::BeginPlay();

	
	GLog->Log(GetActorLocation().ToString());
	
}


