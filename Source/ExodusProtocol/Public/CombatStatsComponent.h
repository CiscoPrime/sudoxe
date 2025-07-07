//=== CombatStatsComponent.h ===============================================
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "EventRouter.h"

#include "CombatStatsComponent.generated.h"

/** Health and other core combat numbers. */
UCLASS(ClassGroup=(Combat), meta=(BlueprintSpawnableComponent))
class UCombatStatsComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UCombatStatsComponent();

    /** Maximum hit points. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
    int32 MaxHealth = 100;

    /** Current hit points. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Stats")
    int32 CurrentHealth = 0;

    virtual void BeginPlay() override;

    /** Lose HP and broadcast to event router. */
    UFUNCTION(BlueprintCallable, Category="Stats")
    void TakeDamage(int32 Amount);
};
