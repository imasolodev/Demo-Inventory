#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEMO_API UItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UItemComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FDataTableRowHandle ItemHandle;

	UPROPERTY()
	TObjectPtr<UDataTable> DataTable;

protected:
	virtual void BeginPlay() override;
	
};
