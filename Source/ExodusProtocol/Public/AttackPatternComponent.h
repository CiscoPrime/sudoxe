//=== AttackPatternComponent.h =============================================
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"

#include "CardPatternTypes.h"

#include "AttackPatternComponent.generated.h"

/** AI helper that chooses which card an enemy will play next. */
UCLASS(ClassGroup=(AI), meta=(BlueprintSpawnableComponent))
class UAttackPatternComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UAttackPatternComponent();

    /** DataTable defining possible actions. */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI")
    TObjectPtr<UDataTable> PatternTable = nullptr;

    /** Pick the next pattern row (placeholder logic). */
    UFUNCTION(BlueprintCallable, Category="AI")
    FCardPatternData ChooseNextPattern() const;
};
