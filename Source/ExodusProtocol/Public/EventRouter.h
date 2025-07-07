#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"

/*  Must sit **before** the generated include so
    the delegate macros can see FCardData           */
#include "CardTypes.h"         

#include "EventRouter.generated.h"   // ← absolutely last include

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCardPlayedEvent,
    const FCardData&, CardData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDamageTakenEvent,
    AActor*, Target, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActorDiedEvent,
    AActor*, DeadActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIntentSelectedEvent,
    FName, CardID, FGameplayTag, PatternTag);

UCLASS(BlueprintType)
class EXODUSPROTOCOL_API UEventRouter : public UObject
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContext"))
    static UEventRouter* Get(const UObject* WorldContext);

    UPROPERTY(BlueprintAssignable) FCardPlayedEvent  OnCardPlayed;
    UPROPERTY(BlueprintAssignable) FDamageTakenEvent OnDamageTaken;
    UPROPERTY(BlueprintAssignable) FActorDiedEvent   OnActorDied;
    UPROPERTY(BlueprintAssignable) FIntentSelectedEvent OnIntentSelected;
};
