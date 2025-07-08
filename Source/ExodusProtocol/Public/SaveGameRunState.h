#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "StatusEffectComponent.h"
#include "SaveGameRunState.generated.h"

/** Save data for a single run. */
UCLASS()
class EXODUSPROTOCOL_API USaveGame_RunState : public USaveGame
{
    GENERATED_BODY()
public:
    /** Player health points. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    int32 PlayerHP = 0;

    /** Current gold amount. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    int32 Gold = 0;

    /** Current cards in the player's deck. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    TArray<FName> DeckCardIDs;

    /** Owned artifact identifiers. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    TArray<FName> ArtifactIDs;

    /** Nodes visited on the world map. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    TArray<FName> VisitedNodeIDs;

    /** Random number generator seed. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    int32 RNGSeed = 0;

    /** ID of the currently selected deck (step 11A). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    FName CurrentDeckID = NAME_None;

    /** Owned attack pattern identifiers (step 11A). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    TArray<FName> OwnedPatternIDs;

    /** Status effects per minion (step 11A). */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RunState")
    TMap<FName, TArray<FActiveStatusEffect>> MinionStatuses;
};

