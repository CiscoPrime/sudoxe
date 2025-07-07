//=== CoreGameMode.cpp =====================================================
#include "CoreGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "EventRouter.h"
#include "CombatManager.h"
#include "RewardManager.h"

ACoreGameMode::ACoreGameMode()
{
    // You can set default pawn, HUD, etc. here if desired.
}

void ACoreGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (EventRouterClass)
    {
        EventRouter = NewObject<UEventRouter>(this, EventRouterClass);
        if (EventRouter)
        {
            EventRouter->AddToRoot(); // ensure it isnt garbage-collected
        }
    }

    if (CombatManagerClass)
    {
        FActorSpawnParameters Params;
        Params.Owner = this;
        CombatManager = GetWorld()->SpawnActor<ACombatManager>(CombatManagerClass, FVector::ZeroVector, FRotator::ZeroRotator, Params);
    }

    if (RewardManagerClass)
    {
        RewardManager = NewObject<URewardManager>(this, RewardManagerClass);
        if (RewardManager)
        {
            RewardManager->AddToRoot();
        }
    }
}

