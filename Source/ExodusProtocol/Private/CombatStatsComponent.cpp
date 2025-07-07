#include "CombatStatsComponent.h"
#include "EventRouter.h"

UCombatStatsComponent::UCombatStatsComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCombatStatsComponent::ApplyDamage(int32 Amount)
{
    if (Amount <= 0 || bIsDead)
    {
        return;
    }

    int32 InitialAmount = Amount;
    int32 Absorbed = FMath::Min(Block, Amount);
    Block -= Absorbed;
    Amount -= Absorbed;

    if (Amount > 0)
    {
        Health -= Amount;
    }

    if (UEventRouter* Router = UEventRouter::Get(this))
    {
        Router->OnDamageTaken.Broadcast(GetOwner(), InitialAmount);
        if (Health <= 0 && !bIsDead)
        {
            bIsDead = true;
            Router->OnActorDied.Broadcast(GetOwner());
        }
    }
}

void UCombatStatsComponent::AddBlock(int32 Amount)
{
    Block += Amount;
}

void UCombatStatsComponent::AddEnergy(int32 Amount)
{
    Energy += Amount;
}
