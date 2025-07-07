//=== CoreGameMode.h =======================================================
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "CoreGameMode.generated.h" // <- Must be the LAST include

class UEventRouter;

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

    /** Blueprint-exposed getter */
    UFUNCTION(BlueprintPure, Category = "Managers")
    FORCEINLINE UEventRouter* GetEventRouter() const { return EventRouter; }

protected:
    virtual void BeginPlay() override;

    /** Class to instantiate; lets you swap router subclasses in Project Settings. */
    UPROPERTY(EditDefaultsOnly, Category = "Managers")
    TSubclassOf<UEventRouter> EventRouterClass;

private:
    /** Live instance kept alive for the whole match. */
    UPROPERTY()
    TObjectPtr<UEventRouter> EventRouter = nullptr;
};
