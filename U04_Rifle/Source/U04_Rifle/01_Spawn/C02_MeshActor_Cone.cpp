#include "C02_MeshActor_Cone.h"
#include "Global.h"

AC02_MeshActor_Cone::AC02_MeshActor_Cone()
{
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/StaticMeshes/SM_Cone.SM_Cone'");
	Mesh->SetStaticMesh(mesh);
}

