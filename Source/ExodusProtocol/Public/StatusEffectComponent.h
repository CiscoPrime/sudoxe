//=== StatusEffectComponent.h ==============================================
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "StatusTypes.h"

#include "StatusEffectComponent.generated.h"

/** Individual stack of an effect currently applied to the owner. */
USTRUCT(BlueprintType)
struct FActiveStatus
{
    GENERATED_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Status")
    FStatusEffectData Data;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Status")
    int32 Stacks = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Status")
    int32 Duration = 0;
};

/** Component tracking status effects like Poison or Strength. */
UCLASS(ClassGroup=(Status), meta=(BlueprintSpawnableComponent))
class UStatusEffectComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UStatusEffectComponent();

    /** Current effects on this actor. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Status")
    TArray<FActiveStatus> ActiveEffects;

    /** Simple adder that ignores stacking rules for now. */
    UFUNCTION(BlueprintCallable, Category="Status")
    void AddStatus(const FStatusEffectData& Data, int32 Stacks, int32 Duration);
};
