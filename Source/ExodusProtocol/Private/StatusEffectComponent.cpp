#include "StatusEffectComponent.h"
#include "Engine/DataTable.h"

UStatusEffectComponent::UStatusEffectComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UStatusEffectComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UStatusEffectComponent::ApplyStatus(const FStatusEffectData& Data, int32 Stacks, int32 Duration)
{
    if (Data.StatusID.IsNone()) { return; }
    const int32 StackValue = Stacks > 0 ? Stacks : Data.BaseStacks;
    const int32 DurationValue = Duration > 0 ? Duration : Data.BaseDuration;

    if (FActiveStatusEffect* Existing = ActiveEffects.FindByPredicate([&](const FActiveStatusEffect& E){ return E.StatusID == Data.StatusID; }))
    {
        switch (Data.Stacking)
        {
            case EStatusStacking::Stack:
                Existing->Stacks += StackValue;
                Existing->Duration = FMath::Max(Existing->Duration, DurationValue);
                break;
            case EStatusStacking::Refresh:
                Existing->Duration = DurationValue;
                break;
            case EStatusStacking::Replace:
                Existing->Stacks = StackValue;
                Existing->Duration = DurationValue;
                break;
        }
    }
    else
    {
        FActiveStatusEffect NewEffect;
        NewEffect.StatusID = Data.StatusID;
        NewEffect.Stacks = StackValue;
        NewEffect.Duration = DurationValue;
        ActiveEffects.Add(NewEffect);
    }
}

void UStatusEffectComponent::ApplyStatusByTag(FGameplayTag StatusTag, int32 Stacks, int32 Duration)
{
    if (!StatusDataTable || !StatusTag.IsValid()) { return; }

    TArray<FName> RowNames = StatusDataTable->GetRowNames();
    for (const FName& RowName : RowNames)
    {
        const FStatusEffectData* Row = StatusDataTable->FindRow<FStatusEffectData>(RowName, TEXT("ApplyStatusByTag"));
        if (Row && Row->GameplayTag == StatusTag)
        {
            ApplyStatus(*Row, Stacks, Duration);
            break;
        }
    }
}

void UStatusEffectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AccumulatedTime += DeltaTime;
    if (AccumulatedTime < 1.0f)
    {
        return;
    }
    AccumulatedTime = 0.f;

    for (int32 i = ActiveEffects.Num() - 1; i >= 0; --i)
    {
        FActiveStatusEffect& Effect = ActiveEffects[i];
        if (Effect.Duration > 0)
        {
            --Effect.Duration;
            if (Effect.Duration <= 0)
            {
                ActiveEffects.RemoveAt(i);
            }
        }
    }
}
