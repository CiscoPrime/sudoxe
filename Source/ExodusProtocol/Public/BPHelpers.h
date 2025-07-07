//=== BPHelpers.h ==========================================================
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "CardTypes.h"      // access to FCardData
#include "StatusTypes.h"    // access to FStatusEffectData

#include "BPHelpers.generated.h" // ← MUST be LAST include

/**
 * Static helper functions callable from any Blueprint.
 * Keep logic here very light; anything heavy should live in components.
 */
UCLASS()
class UBPHelpers : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Grab a card row by ID.  Returns an empty struct (CardID = NAME_None) if not found.
     */
    UFUNCTION(BlueprintPure, Category = "Cards")
    static FCardData FindCardData(const UDataTable* Table, FName RowName);

    /**
     * Simple utility that adds stacks & duration to a status‑effect component on Target.
     * (Assumes you have a UStatusEffectComponent you’ll write later.)
     */
    UFUNCTION(BlueprintCallable, Category = "Status")
    static void ApplyStatusEffect(AActor* Target, const FStatusEffectData& StatusData, int32 Stacks, int32 Duration);
};
