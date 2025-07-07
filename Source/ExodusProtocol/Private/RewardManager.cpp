//=== RewardManager.cpp =====================================================
#include "RewardManager.h"
#include "Engine/DataTable.h"

URewardManager::URewardManager()
{
    RandomStream.GenerateNewSeed();
}

TArray<FCardData> URewardManager::GetRandomCards(int32 Count, FGameplayTag RequiredTag)
{
    TArray<FCardData> Results;
    if (!CardTable) { return Results; }

    TArray<FCardData*> Rows;
    CardTable->GetAllRows(TEXT("GetRandomCards"), Rows);

    if (RequiredTag.IsValid())
    {
        Rows.RemoveAll([&](const FCardData* Row)
        {
            return !(Row->GrantedStatusEffects.Contains(RequiredTag) || Row->StartingStatuses.Contains(RequiredTag));
        });
    }

    while (Rows.Num() > 0 && Results.Num() < Count)
    {
        int32 Index = RandomStream.RandRange(0, Rows.Num() - 1);
        Results.Add(*Rows[Index]);
        Rows.RemoveAt(Index);
    }

    return Results;
}

TArray<FArtifactData> URewardManager::GetRandomArtifacts(int32 Count, FGameplayTag RequiredTag)
{
    TArray<FArtifactData> Results;
    if (!ArtifactTable) { return Results; }

    TArray<FArtifactData*> Rows;
    ArtifactTable->GetAllRows(TEXT("GetRandomArtifacts"), Rows);

    if (RequiredTag.IsValid())
    {
        Rows.RemoveAll([&](const FArtifactData* Row)
        {
            return !Row->GameplayTag.MatchesTag(RequiredTag);
        });
    }

    while (Rows.Num() > 0 && Results.Num() < Count)
    {
        int32 Index = RandomStream.RandRange(0, Rows.Num() - 1);
        Results.Add(*Rows[Index]);
        Rows.RemoveAt(Index);
    }

    return Results;
}

TArray<FName> URewardManager::GetDeckCardIDs(FName DeckID) const
{
    TArray<FName> CardIDs;
    if (!DeckTable || DeckID.IsNone()) { return CardIDs; }

    if (const FDeckData* Row = DeckTable->FindRow<FDeckData>(DeckID, TEXT("GetDeckCardIDs")))
    {
        CardIDs = Row->CardIDs;
    }

    return CardIDs;
}

TArray<FCardPatternData> URewardManager::GetPatternsByTag(FGameplayTag PatternTag) const
{
    TArray<FCardPatternData> Patterns;
    if (!PatternTable) { return Patterns; }

    TArray<FCardPatternData*> Rows;
    PatternTable->GetAllRows(TEXT("GetPatternsByTag"), Rows);

    for (const FCardPatternData* Row : Rows)
    {
        if (!PatternTag.IsValid() || Row->PatternTag.MatchesTag(PatternTag))
        {
            Patterns.Add(*Row);
        }
    }

    return Patterns;
}

