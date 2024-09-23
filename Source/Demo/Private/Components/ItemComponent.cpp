#include "Demo/Public/Components/ItemComponent.h"

UItemComponent::UItemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableObj(TEXT("/Game/Data/ItemDataTable.ItemDataTable"));
	if (DataTableObj.Succeeded())
	{
		ItemHandle.DataTable = DataTableObj.Object;
		DataTable = DataTableObj.Object;
	}
}

void UItemComponent::BeginPlay()
{
	Super::BeginPlay();
}
