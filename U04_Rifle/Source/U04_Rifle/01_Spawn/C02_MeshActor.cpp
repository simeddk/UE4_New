#include "C02_MeshActor.h"
#include "Global.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

AC02_MeshActor::AC02_MeshActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/StaticMeshes/SM_Cone.SM_Cone'");
	Mesh->SetStaticMesh(mesh);
}

void AC02_MeshActor::BeginPlay()
{
	Super::BeginPlay();

	UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), nullptr, L"MaterialInstanceConstant'/Game/Materials/MAT_Wall.MAT_Wall'");
	UMaterialInstanceConstant* material;
	material = Cast<UMaterialInstanceConstant>(obj);
	
	Mesh->SetMaterial(0, material);
}


