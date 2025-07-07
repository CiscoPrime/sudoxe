//=== RewardManager.h =======================================================
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "CardTypes.h"
#include "ArtifactTypes.h"
#include "DeckTypes.h"
#include "CardPatternTypes.h"

#include "RewardManager.generated.h"

/**
 * Provides random card and artifact rewards filtered by gameplay tags.
 * Blueprint subclasses can override or extend behaviour.
 */
UCLASS(BlueprintType)
class EXODUSPROTOCOL_API URewardManager : public UObject
{
    GENERATED_BODY()
public:
    URewardManager();

    /** Data table containing card rows */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
    UDataTable* CardTable = nullptr;

    /** Data table containing artifact rows */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
    UDataTable* ArtifactTable = nullptr;

    /** Optional table of deck rows for bulk rewards */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
    UDataTable* DeckTable = nullptr;

    /** Optional table of pattern rows for AI rewards */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
    UDataTable* PatternTable = nullptr;

    /** Deterministic random stream for unit tests or seeded runs */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Rewards")
    FRandomStream RandomStream;

    /** Pick random cards that grant or start with the given tag (optional). */
    UFUNCTION(BlueprintCallable, Category="Rewards")
    TArray<FCardData> GetRandomCards(int32 Count, FGameplayTag RequiredTag);

    /** Pick random artifacts matching the given tag (optional). */
    UFUNCTION(BlueprintCallable, Category="Rewards")
    TArray<FArtifactData> GetRandomArtifacts(int32 Count, FGameplayTag RequiredTag);

    /** Return card IDs for a deck row. */
    UFUNCTION(BlueprintCallable, Category="Rewards")
    TArray<FName> GetDeckCardIDs(FName DeckID) const;

    /** Return pattern rows whose tag matches the filter (or all if invalid). */
    UFUNCTION(BlueprintCallable, Category="Rewards")
    TArray<FCardPatternData> GetPatternsByTag(FGameplayTag PatternTag) const;
};

