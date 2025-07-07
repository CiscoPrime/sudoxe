//=== CoreGameMode.h =======================================================
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "CoreGameMode.generated.h" // ← Must be the LAST include

class UEventRouter;
class ACombatManager;
class URewardManager;

/**
 * Thin native GameMode that spawns and keeps a reference to the global EventRouter.
 * All other managers (Reward, Combat, etc.) can later read the stored pointer via
 * GetGameMode<ACoreGameMode>() in Blueprint or C++.
 */
UCLASS()
class ACoreGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ACoreGameMode();

    /** Blueprint‑exposed getter */
    UFUNCTION(BlueprintPure, Category = "Managers")
    FORCEINLINE UEventRouter* GetEventRouter() const { return EventRouter; }

    /** Blueprint‑exposed getter */
    UFUNCTION(BlueprintPure, Category = "Managers")
    FORCEINLINE ACombatManager* GetCombatManager() const { return CombatManager; }

    /** Blueprint‑exposed getter */
    UFUNCTION(BlueprintPure, Category = "Managers")
    FORCEINLINE URewardManager* GetRewardManager() const { return RewardManager; }

protected:
    virtual void BeginPlay() override;

    /** Class to instantiate; lets you swap router subclasses in Project Settings. */
    UPROPERTY(EditDefaultsOnly, Category = "Managers")
    TSubclassOf<UEventRouter> EventRouterClass;

    /** Combat manager actor to spawn */
    UPROPERTY(EditDefaultsOnly, Category = "Managers")
    TSubclassOf<ACombatManager> CombatManagerClass;

    /** Reward manager object to instantiate */
    UPROPERTY(EditDefaultsOnly, Category = "Managers")
    TSubclassOf<URewardManager> RewardManagerClass;

private:
    /** Live instance kept alive for the whole match. */
    UPROPERTY()
    TObjectPtr<UEventRouter> EventRouter = nullptr;

    /** Spawned combat manager instance */
    UPROPERTY()
    TObjectPtr<ACombatManager> CombatManager = nullptr;

    /** Live reward manager instance */
    UPROPERTY()
    TObjectPtr<URewardManager> RewardManager = nullptr;
};
