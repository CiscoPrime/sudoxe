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
};
