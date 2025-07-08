#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveGameRunState.h"
#include "SaveSubsystem.generated.h"

/**
 * Simple subsystem wrapping SaveGame operations.
 * Other systems should call the Blueprint functions below whenever
 * player data such as health, gold or deck contents changes so the
 * run state stays persisted to disk.
 */
UCLASS()
class EXODUSPROTOCOL_API USaveSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    /** Save the given run state to disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    bool SaveRunState(USaveGame_RunState* State);

    /** Load the run state from disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    USaveGame_RunState* LoadRunState();

    /** Delete the current save slot. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void DeleteSave();

    /** Update the player's current HP value on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetPlayerHP(int32 NewHP);

    /** Update the player's current gold amount on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetGold(int32 NewGold);

    /** Replace the player's deck card IDs on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetDeckCardIDs(const TArray<FName>& NewIDs);

    /** Replace the player's owned artifact IDs on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetArtifactIDs(const TArray<FName>& NewIDs);

    /** Set the ID of the currently selected deck on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetCurrentDeckID(FName DeckID);

    /** Replace visited node IDs on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetVisitedNodeIDs(const TArray<FName>& NewIDs);

    /** Update the RNG seed value on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetRNGSeed(int32 Seed);

    /** Replace owned attack pattern IDs on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetOwnedPatternIDs(const TArray<FName>& NewIDs);

    /** Replace all saved minion statuses on disk. */
    UFUNCTION(BlueprintCallable, Category="Save")
    void SetMinionStatuses(const TMap<FName, FMinionStatusArray>& Statuses);

private:
    static const FString SlotName;
};

