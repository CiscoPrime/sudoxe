#include "AttackPatternComponent.h"
#include "Engine/DataTable.h"

UAttackPatternComponent::UAttackPatternComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UAttackPatternComponent::BeginPlay()
{
    Super::BeginPlay();
}

FName UAttackPatternComponent::PickNextCard()
{
    if (!PatternTable)
    {
        return NAME_None;
    }

    TArray<FCardPatternData*> Rows;
    PatternTable->GetAllRows<FCardPatternData>(TEXT("PickNextCard"), Rows);
    if (Rows.Num() == 0)
    {
        return NAME_None;
    }

    TArray<const FCardPatternData*> ValidRows;
    int32 TotalWeight = 0;
    for (const FCardPatternData* Row : Rows)
    {
        if (Row->RepeatLimit > 0 && LastCard == Row->CardID && RepeatCount >= Row->RepeatLimit)
        {
            continue;
        }
        ValidRows.Add(Row);
        TotalWeight += FMath::Max(1, Row->Weight);
    }

    if (ValidRows.Num() == 0)
    {
        return NAME_None;
    }

    int32 Roll = FMath::RandRange(1, TotalWeight);
    for (const FCardPatternData* Row : ValidRows)
    {
        Roll -= FMath::Max(1, Row->Weight);
        if (Roll <= 0)
        {
            if (LastCard == Row->CardID)
            {
                ++RepeatCount;
            }
            else
            {
                LastCard = Row->CardID;
                RepeatCount = 1;
            }
            return Row->CardID;
        }
    }

    return NAME_None;
}
