#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardComponent.h"
#include "CardVisualComponent.h"
#include "EventRouter.h"
#include "CardActor.generated.h"

/** Zones a card can occupy during play. */
UENUM(BlueprintType)
enum class ECardZone : uint8
{
    DrawPile UMETA(DisplayName="DrawPile"),
    Hand     UMETA(DisplayName="Hand"),
    Queue    UMETA(DisplayName="Queue"),
    Grave    UMETA(DisplayName="Grave")
};

/** Actor representing a card instance that moves between draw pile, hand, queue and grave. */
UCLASS()
class EXODUSPROTOCOL_API ACardActor : public AActor
{
    GENERATED_BODY()
public:
    ACardActor();

    virtual void BeginPlay() override;

    /** Current lifecycle zone. */
    UPROPERTY(BlueprintReadOnly, Category="Card")
    ECardZone CardZone = ECardZone::DrawPile;

    /** Component holding card data and events. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Card")
    TObjectPtr<UCardComponent> CardComponent;

    /** Handles visual asset and animations for this card. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Card")
    TObjectPtr<UCardVisualComponent> CardVisual;

    /** Move to a new zone and fire the relevant lifecycle events. */
    UFUNCTION(BlueprintCallable, Category="Card")
    void MoveToZone(ECardZone NewZone);

    /** Called after the card is drawn into the player's hand. */
    UFUNCTION(BlueprintImplementableEvent, Category="Card|Visual")
    void OnCardDrawn();

    /** Called when the card is played from the hand. */
    UFUNCTION(BlueprintImplementableEvent, Category="Card|Visual")
    void OnCardPlayed();

    /** Called after the card's effect resolves. */
    UFUNCTION(BlueprintImplementableEvent, Category="Card|Visual")
    void OnCardResolved();

    /** Called when the card is discarded or moved to the grave. */
    UFUNCTION(BlueprintImplementableEvent, Category="Card|Visual")
    void OnCardDiscarded();

    /** Called whenever the attack animation is played. */
    UFUNCTION(BlueprintImplementableEvent, Category="Card|Visual")
    void OnAttack();

    /** Called whenever the defend animation is played. */
    UFUNCTION(BlueprintImplementableEvent, Category="Card|Visual")
    void OnDefend();

    /** Called whenever the walk animation is played. */
    UFUNCTION(BlueprintImplementableEvent, Category="Card|Visual")
    void OnWalk();

    /** Called whenever the retreat animation is played. */
    UFUNCTION(BlueprintImplementableEvent, Category="Card|Visual")
    void OnRetreat();

    /** Trigger attack animation and blueprint event. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayAttack();

    /** Trigger defend animation and blueprint event. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayDefend();

    /** Trigger walk animation and blueprint event. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayWalk();

    /** Trigger retreat animation and blueprint event. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayRetreat();

    /** Trigger idle animation and blueprint event. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayIdle();

protected:
    bool bResolvedBeforeDiscard = false;

    UFUNCTION()
    void HandleDraw();

    UFUNCTION()
    void HandlePlay();

    UFUNCTION()
    void HandleResolve();

    UFUNCTION()
    void HandleDiscard();
};
