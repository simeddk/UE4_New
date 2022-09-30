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

	UMaterialInstanceConstant* material;
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Materials/MAT_Wall.MAT_Wall'");
	
	Material = UMaterialInstanceDynamic::Create(material, this);
	Mesh->SetMaterial(0, Material);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.f, true);
}

void AC02_MeshActor::ChangeColor()
{
	FLinearColor color;
	color.R = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
	color.G = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
	color.B = UKismetMathLibrary::RandomFloatInRange(0.f, 1.f);
	color.A = 1.f;

	Material->SetVectorParameterValue("BaseColor", color);
	Material->SetScalarParameterValue("Metallic", color.R);
	Material->SetScalarParameterValue("Roughness", color.G);
}


