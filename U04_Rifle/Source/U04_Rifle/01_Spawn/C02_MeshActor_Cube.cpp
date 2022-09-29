#include "C02_MeshActor_Cube.h"
#include "Global.h"

AC02_MeshActor_Cube::AC02_MeshActor_Cube()
{
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/StaticMeshes/SM_Cube.SM_Cube'");
	Mesh->SetStaticMesh(mesh);
}

