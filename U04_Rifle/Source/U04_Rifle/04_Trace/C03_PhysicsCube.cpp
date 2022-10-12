#include "C03_PhysicsCube.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"

AC03_PhysicsCube::AC03_PhysicsCube()
{
	CHelpers::CreateComponent<UStaticMeshComponent>(this, &Mesh, "Mesh");

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/StaticMeshes/SM_Cube.SM_Cube'");
	Mesh->SetStaticMesh(mesh);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetWorldScale3D(FVector(0.7f));
	Mesh->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
}

void AC03_PhysicsCube::BeginPlay()
{
	Super::BeginPlay();
	
}

