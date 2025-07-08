//=== CardTypes.h ==========================================================
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h" // Remove if you won't use GameplayTags
#include "Blueprint/UserWidget.h" // for CardVisualWidget
#include "Engine/DataTable.h"
#include "PaperSprite.h"              // for UPaperSprite
#include "PaperFlipbook.h"            // for UPaperFlipbook
#include "Animation/AnimationAsset.h"

#include "CardTypes.generated.h" // ← Must be the LAST include in this header

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

/** Visual assets used when representing a card's effect or spawned actor. */
USTRUCT(BlueprintType)
struct FCardVisualData : public FTableRowBase
{
    GENERATED_BODY();

    /** Simple 2D sprite for minimal representations. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card|Visual")
    TObjectPtr<UPaperSprite> Sprite = nullptr;

    /** Animated flipbook for 2D characters. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card|Visual")
    TObjectPtr<UPaperFlipbook> Flipbook = nullptr;

    /** Skeletal mesh used for 3D representation. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card|Visual")
    TObjectPtr<USkeletalMesh> SkeletalMesh = nullptr;

    /** Animation played while idle. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card|Visual")
    TObjectPtr<UAnimationAsset> IdleAnimation = nullptr;

    /** Animation played when attacking. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card|Visual")
    TObjectPtr<UAnimationAsset> AttackAnimation = nullptr;

    /** Animation played while defending. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card|Visual")
    TObjectPtr<UAnimationAsset> DefendAnimation = nullptr;

    /** Animation used for walking or movement. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card|Visual")
    TObjectPtr<UAnimationAsset> WalkAnimation = nullptr;

    /** Animation used for retreat or death. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Card|Visual")
    TObjectPtr<UAnimationAsset> RetreatAnimation = nullptr;
};


/**
 * Pure‑data definition of a card.  No behaviour here—only the numbers and identifiers that
 * designers tune in the editor.
 */
USTRUCT(BlueprintType)
struct FCardData : public FTableRowBase
{
    GENERATED_BODY()

    /** Internal name for look‑ups (e.g. "Strike_Red"). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    FName CardID = NAME_None;

    /** Localised display name that shows on the UI card frame. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    FText DisplayName;

    /** Optional portrait texture shown in the custom card frame. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    TObjectPtr<UTexture2D> Portrait = nullptr;

    /** Card frame backing image. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card|Visual")
    TObjectPtr<UTexture2D> Frame = nullptr;

    /** Tint applied to the frame texture. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card|Visual")
    FLinearColor FrameTint = FLinearColor::White;

    /** Optional widget class used for the in-hand visual. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card|Visual")
    TSubclassOf<UUserWidget> CardVisualWidget;

    /** Models and animations used when this card spawns an actor. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card|Visual")
    FCardVisualData Visual;

    /** Broad gameplay bucket (Attack, Skill, etc.). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    ECardType CardType = ECardType::Attack;

    /** Drop‑rate bucket for rewards. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    ECardRarity Rarity = ECardRarity::Common;

    /** Energy cost shown in the top‑left pip. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    int32 EnergyCost = 1;

    /** Number fed into damage formulas; 0 for non‑damage cards. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    int32 BaseDamage = 0;

    /** Number fed into block formulas; 0 for non‑block cards. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    int32 BaseBlock = 0;

    /** Tags of status effects this card applies when it resolves. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    TArray<FGameplayTag> GrantedStatusEffects;

    /** Status effects automatically present when the card is drawn. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    TArray<FGameplayTag> StartingStatuses;

    /** How many times the card's effect repeats. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
    int32 Repetitions = 1;
};

