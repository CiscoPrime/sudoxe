//=== AttackPatternComponent.cpp ===========================================
#include "AttackPatternComponent.h"

#include "Engine/DataTable.h"

UAttackPatternComponent::UAttackPatternComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

FCardPatternData UAttackPatternComponent::ChooseNextPattern() const
{
    if (!PatternTable)
    {
        return FCardPatternData();
    }

    const TArray<FName> RowNames = PatternTable->GetRowNames();
    if (RowNames.Num() > 0)
    {
        if (const FCardPatternData* Row = PatternTable->FindRow<FCardPatternData>(RowNames[0], TEXT("ChooseNextPattern")))
        {
            return *Row;
        }
    }
    return FCardPatternData();
}
