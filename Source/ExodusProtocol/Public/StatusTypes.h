#pragma once
//=== StatusTypes.h ========================================================
#include "CoreMinimal.h"
#include "GameplayTagContainer.h" // Remove if you won't use GameplayTags
#include "Engine/DataTable.h"

#include "StatusTypes.generated.h" // ← Must be the LAST include in this header

/**
 * Broad grouping used by UI (green vs. red) and balance logic.
 */
UENUM(BlueprintType)
enum class EStatusCategory : uint8
{
    Buff        UMETA(DisplayName = "Buff"),
    Debuff      UMETA(DisplayName = "Debuff")
};

/**
 * How a new application interacts with an existing stack of the same effect.
 */
UENUM(BlueprintType)
enum class EStatusStacking : uint8
{
    /** Adds its stacks on top of what’s already there. */
    Stack       UMETA(DisplayName = "Stack"),

    /** Resets the remaining duration but keeps current stacks. */
    Refresh     UMETA(DisplayName = "Refresh"),

    /** Wipes the old effect and starts fresh (duration + stacks). */
    Replace     UMETA(DisplayName = "Replace")
};

/**
 * Pure‑data description of a status effect (Bleed, Strength, Vulnerable…).
 * Designers tweak these in DataTables / PrimaryDataAssets.
 */
USTRUCT(BlueprintType)
struct FStatusEffectData : public FTableRowBase
{
    GENERATED_BODY()

    /** Internal ID for look‑ups (e.g. "Bleed"). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Status")
    FName StatusID = NAME_None;

    /** Name shown in tooltips. Supports localisation. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Status")
    FText DisplayName;

    /** 32×32 or 64×64 icon used in the HUD. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Status")
    TObjectPtr<UTexture2D> Icon = nullptr;

    /** Buff vs. Debuff for colour‑coding and certain rules. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Status")
    EStatusCategory Category = EStatusCategory::Debuff;

    /** Stacking rule when the same effect is applied again. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Status")
    EStatusStacking Stacking = EStatusStacking::Stack;

    /** Default turns this effect lasts if not specified elsewhere. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Status")
    int32 BaseDuration = 1;

    /** Default stack amount if a card applies the effect without a value. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Status")
    int32 BaseStacks = 1;

    /** Optional gameplay tag for quick queries in code/BP. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Status")
    FGameplayTag GameplayTag;
};
