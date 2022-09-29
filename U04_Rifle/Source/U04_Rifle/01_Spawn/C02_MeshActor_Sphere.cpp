#include "C02_MeshActor_Sphere.h"
#include "Global.h"

AC02_MeshActor_Sphere::AC02_MeshActor_Sphere()
{
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/StaticMeshes/SM_Sphere.SM_Sphere'");
	Mesh->SetStaticMesh(mesh);
}

