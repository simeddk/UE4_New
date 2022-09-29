#include "C02_MeshActor_Cylinder.h"
#include "Global.h"

AC02_MeshActor_Cylinder::AC02_MeshActor_Cylinder()
{
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh,"StaticMesh'/Game/StaticMeshes/SM_Cylinder.SM_Cylinder'");
	Mesh->SetStaticMesh(mesh);
}