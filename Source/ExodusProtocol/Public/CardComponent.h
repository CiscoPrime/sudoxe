//=== CardComponent.h ======================================================
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "CardTypes.h"
#include "EventRouter.h"

#include "CardComponent.generated.h"

/** Component that stores data for an individual card instance. */
UCLASS(ClassGroup=(Card), meta=(BlueprintSpawnableComponent))
class UCardComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UCardComponent();

    /** Data describing this card. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Card")
    FCardData CardData;

    /** Assign new card data at runtime. */
    UFUNCTION(BlueprintCallable, Category="Card")
    void SetCardData(const FCardData& Data);

    /** Broadcasts OnCardPlayed via the global event router. */
    UFUNCTION(BlueprintCallable, Category="Card")
    void PlayCard();
};
