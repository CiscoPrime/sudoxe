#include "CombatManager.h"
#include "CombatStatsComponent.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "AttackPatternComponent.h"
#include "EventRouter.h"

ACombatManager::ACombatManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ACombatManager::BeginPlay()
{
    Super::BeginPlay();
    StartPlayerTurn();
}

UCombatStatsComponent* ACombatManager::GetStats(APawn* Pawn) const
{
    return Pawn ? Pawn->FindComponentByClass<UCombatStatsComponent>() : nullptr;
}

void ACombatManager::StartPlayerTurn()
{
    bPlayerTurn = true;
    if (UCombatStatsComponent* Stats = GetStats(PlayerPawn))
    {
        Stats->Energy = 3;
    }
    OnPlayerTurnStarted.Broadcast();
}

void ACombatManager::EndPlayerTurn()
{
    OnPlayerTurnEnded.Broadcast();
    StartEnemyTurn();
}

void ACombatManager::StartEnemyTurn()
{
    bPlayerTurn = false;
    if (UCombatStatsComponent* Stats = GetStats(EnemyPawn))
    {
        Stats->Energy = 3;
    }
    if (UAttackPatternComponent* Pattern =
            EnemyPawn ? EnemyPawn->FindComponentByClass<UAttackPatternComponent>() : nullptr)
    {
        Pattern->PickNextCard();
    }
    OnEnemyTurnStarted.Broadcast();
}

void ACombatManager::EndEnemyTurn()
{
    OnEnemyTurnEnded.Broadcast();
    ++Round;
    StartPlayerTurn();
}

