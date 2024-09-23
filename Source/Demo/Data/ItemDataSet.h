#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemDataSet.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon,
	Armour,
	Consumable,
	Misc
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	AssaultRifle,
	SMG,
	Pistol,
	Sniper,
	Melee
};

UENUM(BlueprintType)
enum class EArmourType : uint8
{
	Bronze,
	Iron,
	Steel
};

UENUM(BlueprintType)
enum class EConsumableType : uint8
{
	Health,
	Mana,
	Shield
};

USTRUCT(BlueprintType)
struct FItemTextData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FText ItemName;

	UPROPERTY(EditAnywhere)
	FText ItemDescription;
	
	UPROPERTY(EditAnywhere)
	FText ItemTooltip;

	FItemTextData() :
	ItemName(FText::GetEmpty()),
	ItemDescription(FText::GetEmpty()),
	ItemTooltip(FText::GetEmpty())
	{}
};

USTRUCT(BlueprintType)
struct FItemAssetData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UStaticMesh> ItemMesh;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UTexture2D> ItemIcon;

	FItemAssetData() :
	ItemMesh(nullptr),
	ItemIcon(nullptr)
	{}
};

USTRUCT(BlueprintType)
struct FItemNumericData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float ItemWeight;

	UPROPERTY(EditAnywhere)
	int32 MaxQuantity;

	FItemNumericData() :
	ItemWeight(0.0f),
	MaxQuantity(1)
	{}
};

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 Range;

	UPROPERTY(EditAnywhere)
	int32 MaxAmmo;

	UPROPERTY(EditAnywhere)
	int32 ClipSize;

	UPROPERTY(EditAnywhere)
	float FireRate;

	UPROPERTY(EditAnywhere)
	float ReloadSpeed;

	UPROPERTY(EditAnywhere)
	float PitchRecoil;

	FWeaponData() :
	Range(5000),
	MaxAmmo(250),
	ClipSize(20),
	FireRate(0.1f),
	ReloadSpeed(1.0f),
	PitchRecoil(-0.05f)
	{}
};

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EItemType ItemType;

	UPROPERTY(EditAnywhere)
	TSoftClassPtr<AActor> ItemClass;

	UPROPERTY(EditAnywhere)
	FItemTextData TextData;

	UPROPERTY(EditAnywhere)
	FItemAssetData AssetData;

	UPROPERTY(EditAnywhere)
	FItemNumericData NumericData;

	UPROPERTY(EditAnywhere)
	FWeaponData WeaponData;
};
