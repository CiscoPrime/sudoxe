//=== CombatStatsComponent.cpp =============================================
#include "CombatStatsComponent.h"

#include "GameFramework/Actor.h"

UCombatStatsComponent::UCombatStatsComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCombatStatsComponent::BeginPlay()
{
    Super::BeginPlay();
    CurrentHealth = MaxHealth;
}

void UCombatStatsComponent::TakeDamage(int32 Amount)
{
    CurrentHealth = FMath::Clamp(CurrentHealth - Amount, 0, MaxHealth);
    if (UEventRouter* Router = UEventRouter::Get(this))
    {
        Router->OnDamageTaken.Broadcast(GetOwner(), Amount);
    }
}
