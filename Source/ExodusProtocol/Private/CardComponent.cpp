#include "CardComponent.h"
#include "StatusEffectComponent.h"

UCardComponent::UCardComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCardComponent::BeginPlay()
{
    Super::BeginPlay();

    if (UStatusEffectComponent* StatusComp = GetOwner()->FindComponentByClass<UStatusEffectComponent>())
    {
        for (const FGameplayTag& Tag : CardData.StartingStatuses)
        {
            StatusComp->ApplyStatusByTag(Tag, 0, 0);
        }
    }
}

void UCardComponent::TriggerDraw()
{
    OnDraw.Broadcast();
}

void UCardComponent::TriggerPlay()
{
    OnPlay.Broadcast();
}

void UCardComponent::TriggerResolve()
{
    OnResolve.Broadcast();
}

void UCardComponent::TriggerDiscard()
{
    OnDiscard.Broadcast();
}
