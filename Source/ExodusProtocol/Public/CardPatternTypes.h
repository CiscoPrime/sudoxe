#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"

#include "CardPatternTypes.generated.h"

/** Row describing how AI chooses cards to play. */
USTRUCT(BlueprintType)
struct FCardPatternData : public FTableRowBase
{
    GENERATED_BODY();

    /** Card to play. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pattern")
    FName CardID = NAME_None;

    /** Weight used for random selection. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pattern")
    int32 Weight = 1;

    /** How many times this card can be repeated in a row. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pattern")
    int32 RepeatLimit = 0;

    /** Optional tag for conditional logic. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pattern")
    FGameplayTag PatternTag;
};

