#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CombatManager.generated.h"

class APawn;
class UCombatStatsComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTurnEvent);

/** Simple actor that manages player/enemy turn flow. */
UCLASS()
class EXODUSPROTOCOL_API ACombatManager : public AActor
{
    GENERATED_BODY()
public:
    ACombatManager();

    UPROPERTY(BlueprintReadOnly, Category="Combat")
    int32 Round = 1;

    UPROPERTY(BlueprintReadOnly, Category="Combat")
    bool bPlayerTurn = true;

    UPROPERTY(BlueprintReadWrite, Category="Combat")
    TObjectPtr<APawn> PlayerPawn = nullptr;

    UPROPERTY(BlueprintReadWrite, Category="Combat")
    TObjectPtr<APawn> EnemyPawn = nullptr;

    UPROPERTY(BlueprintAssignable, Category="Combat")
    FTurnEvent OnPlayerTurnStarted;

    UPROPERTY(BlueprintAssignable, Category="Combat")
    FTurnEvent OnPlayerTurnEnded;

    UPROPERTY(BlueprintAssignable, Category="Combat")
    FTurnEvent OnEnemyTurnStarted;

    UPROPERTY(BlueprintAssignable, Category="Combat")
    FTurnEvent OnEnemyTurnEnded;

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category="Combat")
    void StartPlayerTurn();

    UFUNCTION(BlueprintCallable, Category="Combat")
    void EndPlayerTurn();

    UFUNCTION(BlueprintCallable, Category="Combat")
    void StartEnemyTurn();

    UFUNCTION(BlueprintCallable, Category="Combat")
    void EndEnemyTurn();

    UFUNCTION(BlueprintPure, Category="Combat")
    FORCEINLINE APawn* GetActivePawn() const { return bPlayerTurn ? PlayerPawn : EnemyPawn; }

private:
    UCombatStatsComponent* GetStats(APawn* Pawn) const;
};

