#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatusTypes.h"
#include "Engine/DataTable.h"
#include "StatusEffectComponent.generated.h"

USTRUCT(BlueprintType)
struct FActiveStatusEffect
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status")
    FName StatusID = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status")
    int32 Stacks = 0;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Status")
    int32 Duration = 0;
};

/** Component that tracks active status effects on an Actor. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EXODUSPROTOCOL_API UStatusEffectComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UStatusEffectComponent();

    /** Apply the given status effect using optional stacks/duration overrides. */
    UFUNCTION(BlueprintCallable, Category="Status")
    void ApplyStatus(const FStatusEffectData& Data, int32 Stacks = 1, int32 Duration = 1);

    /** Convenience look-up using the StatusDataTable and a GameplayTag. */
    UFUNCTION(BlueprintCallable, Category="Status")
    void ApplyStatusByTag(FGameplayTag StatusTag, int32 Stacks = 0, int32 Duration = 0);

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(BlueprintReadOnly, Category="Status")
    TArray<FActiveStatusEffect> ActiveEffects;

protected:
    virtual void BeginPlay() override;

    /** Table used to resolve status tags into data rows. */
    UPROPERTY(EditDefaultsOnly, Category="Status")
    UDataTable* StatusDataTable = nullptr;

private:
    float AccumulatedTime = 0.f;
};
