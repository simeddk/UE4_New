#include "C06_Cubes.h"
#include "Global.h"
#include "C05_MultiTrigger.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

AC06_Cubes::AC06_Cubes()
{
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);
	
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/StaticMeshes/SM_Cube.SM_Cube'");

	for (int32 i = 0; i < 3; i++)
	{
		FString str;
		str.Append("Mesh");
		str.Append(FString::FromInt(i + 1));

		CHelpers::CreateComponent<UStaticMeshComponent>(this, &Meshes[i], FName(str), Scene);
		Meshes[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		Meshes[i]->SetSimulatePhysics(false);
		Meshes[i]->SetStaticMesh(mesh);
	}

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->TextRenderColor = FColor::Black;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());
}

void AC06_Cubes::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC05_MultiTrigger::StaticClass(), actors);
	CheckFalse(actors.Num() > 0);

	AC05_MultiTrigger* trigger = Cast<AC05_MultiTrigger>(actors[0]);
	trigger->OnMultiBeginOverlap.AddUFunction(this, "OnDropAndChangeColor");

	UMaterialInstanceConstant* material;
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Materials/MAT_Wall.MAT_Wall'");

	for (int32 i = 0; i < 3; i++)
	{
		Materials[i] = UMaterialInstanceDynamic::Create(material, this);
		Meshes[i]->SetMaterial(0, Materials[i]);

		FirstLocations[i] = Meshes[i]->GetComponentToWorld().GetLocation();
	}
}

void AC06_Cubes::OnDropAndChangeColor(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
	{
		Meshes[i]->SetSimulatePhysics(false);
		Meshes[i]->SetWorldLocation(FirstLocations[i]);

		Materials[i]->SetVectorParameterValue("BaseColor", FLinearColor(0.3f, 0.3f, 0.3f));
	}

	Meshes[InIndex]->SetSimulatePhysics(true);
	Materials[InIndex]->SetVectorParameterValue("BaseColor", InColor);
}

