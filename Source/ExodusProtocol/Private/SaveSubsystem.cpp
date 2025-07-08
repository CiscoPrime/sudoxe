#include "SaveSubsystem.h"
#include "Kismet/GameplayStatics.h"

const FString USaveSubsystem::SlotName = TEXT("RunState");

bool USaveSubsystem::SaveRunState(USaveGame_RunState* State)
{
    if (!State) { return false; }
    return UGameplayStatics::SaveGameToSlot(State, SlotName, 0);
}

USaveGame_RunState* USaveSubsystem::LoadRunState()
{
    if (USaveGame* Loaded = UGameplayStatics::LoadGameFromSlot(SlotName, 0))
    {
        return Cast<USaveGame_RunState>(Loaded);
    }
    return nullptr;
}

void USaveSubsystem::DeleteSave()
{
    UGameplayStatics::DeleteGameInSlot(SlotName, 0);
}

