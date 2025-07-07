#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatStatsComponent.generated.h"

class UEventRouter;

/** Tracks health, block and energy for an actor. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EXODUSPROTOCOL_API UCombatStatsComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UCombatStatsComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Health = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Block = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 Energy = 3;

    UFUNCTION(BlueprintCallable, Category="Stats")
    void ApplyDamage(int32 Amount);

    UFUNCTION(BlueprintCallable, Category="Stats")
    void AddBlock(int32 Amount);

    UFUNCTION(BlueprintCallable, Category="Stats")
    void AddEnergy(int32 Amount);

private:
    bool bIsDead = false;
};
