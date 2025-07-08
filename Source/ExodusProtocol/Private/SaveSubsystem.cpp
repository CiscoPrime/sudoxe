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

void USaveSubsystem::SetPlayerHP(int32 NewHP)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->PlayerHP = NewHP;
    SaveRunState(State);
}

void USaveSubsystem::SetGold(int32 NewGold)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->Gold = NewGold;
    SaveRunState(State);
}

void USaveSubsystem::SetDeckCardIDs(const TArray<FName>& NewIDs)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->DeckCardIDs = NewIDs;
    SaveRunState(State);
}

void USaveSubsystem::SetArtifactIDs(const TArray<FName>& NewIDs)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->ArtifactIDs = NewIDs;
    SaveRunState(State);
}

void USaveSubsystem::SetCurrentDeckID(FName DeckID)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->CurrentDeckID = DeckID;
    SaveRunState(State);
}

void USaveSubsystem::SetVisitedNodeIDs(const TArray<FName>& NewIDs)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->VisitedNodeIDs = NewIDs;
    SaveRunState(State);
}

void USaveSubsystem::SetRNGSeed(int32 Seed)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->RNGSeed = Seed;
    SaveRunState(State);
}

void USaveSubsystem::SetOwnedPatternIDs(const TArray<FName>& NewIDs)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->OwnedPatternIDs = NewIDs;
    SaveRunState(State);
}

void USaveSubsystem::SetMinionStatuses(const TMap<FName, FMinionStatusArray>& Statuses)
{
    USaveGame_RunState* State = LoadRunState();
    if (!State)
    {
        State = NewObject<USaveGame_RunState>();
    }
    State->MinionStatuses = Statuses;
    SaveRunState(State);
}

