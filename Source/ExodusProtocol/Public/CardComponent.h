#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CardTypes.h"
#include "CardComponent.generated.h"

class UStatusEffectComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCardLifecycleEvent);

/** Component representing a single card instance. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EXODUSPROTOCOL_API UCardComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UCardComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
    FCardData CardData;

    UPROPERTY(BlueprintAssignable, Category="Card")
    FCardLifecycleEvent OnDraw;

    UPROPERTY(BlueprintAssignable, Category="Card")
    FCardLifecycleEvent OnPlay;

    UPROPERTY(BlueprintAssignable, Category="Card")
    FCardLifecycleEvent OnResolve;

    UPROPERTY(BlueprintAssignable, Category="Card")
    FCardLifecycleEvent OnDiscard;

    UFUNCTION(BlueprintCallable, Category="Card")
    void TriggerDraw();

    UFUNCTION(BlueprintCallable, Category="Card")
    void TriggerPlay();

    UFUNCTION(BlueprintCallable, Category="Card")
    void TriggerResolve();

    UFUNCTION(BlueprintCallable, Category="Card")
    void TriggerDiscard();

protected:
    virtual void BeginPlay() override;
};
