#include "Demo/Public/Items/BaseItem.h"
#include "Components/SphereComponent.h"
#include "Demo/Data/ItemDataSet.h"
#include "Demo/Public/Components/ItemComponent.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>("Item Mesh");
	ItemMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	ItemMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	SetRootComponent(ItemMesh);

	ItemSphere = CreateDefaultSubobject<USphereComponent>("Item Sphere");
	ItemSphere->SetSphereRadius(75.0f);
	ItemSphere->SetLineThickness(1.0f);
	ItemSphere->ShapeColor = FColor::Emerald;
	ItemSphere->SetupAttachment(GetRootComponent());

	ItemComponent = CreateDefaultSubobject<UItemComponent>("Item Component");
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();

	ItemMesh->SetSimulatePhysics(true);
}

void ABaseItem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (!ItemComponent->DataTable) { return; }

	const FItemData* FoundData = ItemComponent->DataTable->FindRow<FItemData>(ItemComponent->ItemHandle.RowName, "");
	if (!FoundData) { return; }

	UStaticMesh* LoadedMesh = FoundData->AssetData.ItemMesh.LoadSynchronous();
	ItemMesh->SetStaticMesh(LoadedMesh);
}
