//=== StatusEffectComponent.cpp ============================================
#include "StatusEffectComponent.h"

UStatusEffectComponent::UStatusEffectComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UStatusEffectComponent::AddStatus(const FStatusEffectData& Data, int32 Stacks, int32 Duration)
{
    FActiveStatus NewStatus;
    NewStatus.Data = Data;
    NewStatus.Stacks = Stacks;
    NewStatus.Duration = Duration;
    ActiveEffects.Add(NewStatus);
}
