//=== ArtifactTypes.h ======================================================
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"        // Remove if you don’t plan to tag artifacts

#include "ArtifactTypes.generated.h"     // ← must be the last include

/** How rare an artifact is when rewards are rolled. */
UENUM(BlueprintType)
enum class EArtifactRarity : uint8
{
    Common      UMETA(DisplayName = "Common"),
    Uncommon    UMETA(DisplayName = "Uncommon"),
    Rare        UMETA(DisplayName = "Rare"),
    Epic        UMETA(DisplayName = "Epic"),
    Legendary   UMETA(DisplayName = "Legendary")
};

/** Pure‑data row for a DataTable of artifacts. No behaviour—just numbers and text. */
USTRUCT(BlueprintType)
struct FArtifactData : public FTableRowBase
{
    GENERATED_BODY()

    /** Internal ID (e.g. "BagOfMarbles"). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Artifact")
    FName ArtifactID = NAME_None;

    /** Name shown to the player. Localisable. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Artifact")
    FText DisplayName;

    /** Short description that appears in the tooltip. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Artifact")
    FText Description;

    /** 64×64 icon used in reward and inventory screens. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Artifact")
    TObjectPtr<UTexture2D> Icon = nullptr;

    /** Rarity bucket for reward tables and shop pricing. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Artifact")
    EArtifactRarity Rarity = EArtifactRarity::Common;

    /** Price if this artifact appears in a shop. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Artifact")
    int32 GoldValue = 50;

    /** Optional gameplay tags (e.g. “Artifact.Passive.BlockBoost”). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Artifact")
    FGameplayTag GameplayTag;
};
