//=== CardTypes.h ==========================================================
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h" // Remove if you won't use GameplayTags

#include "CardTypes.generated.h" // <- Must be the LAST include in this header

/**
 * Classification for rules & UI.
 */
UENUM(BlueprintType)
enum class ECardType : uint8
{
    Attack      UMETA(DisplayName = "Attack"),
    Skill       UMETA(DisplayName = "Skill"),
    Power       UMETA(DisplayName = "Power"),
    Curse       UMETA(DisplayName = "Curse"),
    Status      UMETA(DisplayName = "Status")
};

UENUM(BlueprintType)
enum class ECardRarity : uint8
{
    Common      UMETA(DisplayName = "Common"),
    Uncommon    UMETA(DisplayName = "Uncommon"),
    Rare        UMETA(DisplayName = "Rare"),
    Epic        UMETA(DisplayName = "Epic"),
    Legendary   UMETA(DisplayName = "Legendary")
};

/**
 * Pure-data definition of a card.  No behaviour here - only the numbers and identifiers that
 * designers tune in the editor.
 */
USTRUCT(BlueprintType)
struct FCardData
{
    GENERATED_BODY()

    /** Internal name for look-ups (e.g. "Strike_Red"). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    FName CardID = NAME_None;

    /** Localised display name that shows on the UI card frame. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    FText DisplayName;

    /** Optional portrait texture shown in the custom card frame. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    TObjectPtr<UTexture2D> Portrait = nullptr;

    /** Broad gameplay bucket (Attack, Skill, etc.). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    ECardType CardType = ECardType::Attack;

    /** Drop-rate bucket for rewards. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    ECardRarity Rarity = ECardRarity::Common;

    /** Energy cost shown in the top-left pip. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    int32 EnergyCost = 1;

    /** Number fed into damage formulas; 0 for non-damage cards. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    int32 BaseDamage = 0;

    /** Number fed into block formulas; 0 for non-block cards. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    int32 BaseBlock = 0;

    /** Tags of status effects this card applies when it resolves. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    TArray<FGameplayTag> GrantedStatusEffects;
};
