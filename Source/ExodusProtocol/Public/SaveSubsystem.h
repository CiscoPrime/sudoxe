#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SaveGameRunState.h"
#include "SaveSubsystem.generated.h"

/** Simple subsystem wrapping SaveGame operations. */
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

private:
    static const FString SlotName;
};

