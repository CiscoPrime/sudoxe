#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"

#include "MinionTypes.generated.h"

/** Data for an enemy or ally minion. */
USTRUCT(BlueprintType)
struct FMinionData : public FTableRowBase
{
    GENERATED_BODY();

    /** Row identifier. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Minion")
    FName MinionID = NAME_None;

    /** Display name shown on UI. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Minion")
    FText DisplayName;

    /** Mesh or visual asset for spawning. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Minion")
    TObjectPtr<USkeletalMesh> Mesh = nullptr;

    /** Deck row this minion draws cards from. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Minion")
    FName DeckID = NAME_None;

    /** Optional attack pattern row used by AI. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Minion")
    FName AttackPatternID = NAME_None;
};

