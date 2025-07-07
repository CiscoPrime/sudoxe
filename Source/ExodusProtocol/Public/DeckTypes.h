#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"

#include "DeckTypes.generated.h"

/** Data describing a starter or enemy deck. */
USTRUCT(BlueprintType)
struct FDeckData : public FTableRowBase
{
    GENERATED_BODY();

    /** Internal row name / ID. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Deck")
    FName DeckID = NAME_None;

    /** Cards included in this deck by ID. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Deck")
    TArray<FName> CardIDs;
};

