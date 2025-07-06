//=== BPHelpers.cpp ========================================================
#include "BPHelpers.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"

FCardData UBPHelpers::FindCardData(const UDataTable* Table, FName RowName)
{
    if (!Table) { return FCardData(); }
    const FCardData* RowPtr = Table->FindRow<FCardData>(RowName, TEXT("FindCardData"));
    return RowPtr ? *RowPtr : FCardData();
}

void UBPHelpers::ApplyStatusEffect(AActor* Target, const FStatusEffectData& StatusData, int32 Stacks, int32 Duration)
{
    if (!Target) { return; }

    // Placeholder: you will replace this with real component logic.
    UE_LOG(LogTemp, Verbose, TEXT("ApplyStatusEffect %s to %s: %d stacks for %d turns"),
        *StatusData.StatusID.ToString(), *Target->GetName(), Stacks, Duration);
}
