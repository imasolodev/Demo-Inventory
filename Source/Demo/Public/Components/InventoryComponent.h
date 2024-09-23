#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class ADemoCharacter;

USTRUCT(BlueprintType)
struct FItemInventory
{
	GENERATED_BODY()

	FName ID;
	int32 Quantity;
	TSoftClassPtr<AActor> Class;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEMO_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	UPROPERTY()
	TObjectPtr<ADemoCharacter> PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemInventory> ItemInventory;

protected:
	virtual void BeginPlay() override;
};
