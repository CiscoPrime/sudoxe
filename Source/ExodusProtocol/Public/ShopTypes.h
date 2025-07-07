//=== ShopTypes.h ===========================================================
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "ShopTypes.generated.h"

/** Type of item a shop entry sells. */
UENUM(BlueprintType)
enum class EShopItemType : uint8
{
    Card        UMETA(DisplayName = "Card"),
    Artifact    UMETA(DisplayName = "Artifact")
};

/** Row for an item sold in a shop. */
USTRUCT(BlueprintType)
struct FShopItemData : public FTableRowBase
{
    GENERATED_BODY();

    /** Whether this is a card or artifact. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Shop")
    EShopItemType ItemType = EShopItemType::Card;

    /** ID referencing a card or artifact row. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Shop")
    FName ItemID = NAME_None;

    /** Price in whatever currency your game uses. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Shop")
    int32 Price = 0;
};

/** Collection of items a shop offers. */
USTRUCT(BlueprintType)
struct FShopData : public FTableRowBase
{
    GENERATED_BODY();

    /** Row identifier for lookups. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Shop")
    FName ShopID = NAME_None;

    /** Items that this shop can sell. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Shop")
    TArray<FShopItemData> Items;
};
