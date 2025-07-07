//=== BPHelpers.cpp ========================================================
#include "BPHelpers.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "StatusEffectComponent.h"

FCardData UBPHelpers::FindCardData(const UDataTable* Table, FName RowName)
{
    if (!Table) { return FCardData(); }
    const FCardData* RowPtr = Table->FindRow<FCardData>(RowName, TEXT("FindCardData"));
    return RowPtr ? *RowPtr : FCardData();
}

void UBPHelpers::ApplyStatusEffect(AActor* Target, const FStatusEffectData& StatusData, int32 Stacks, int32 Duration)
{
    if (!Target) { return; }

    if (UStatusEffectComponent* StatusComp = Target->FindComponentByClass<UStatusEffectComponent>())
    {
        StatusComp->ApplyStatus(StatusData, Stacks, Duration);
    }
}
