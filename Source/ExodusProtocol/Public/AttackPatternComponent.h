#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CardPatternTypes.h"
#include "Engine/DataTable.h"
#include "AttackPatternComponent.generated.h"

/** Chooses cards for enemy AI based on a weighted pattern table. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EXODUSPROTOCOL_API UAttackPatternComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UAttackPatternComponent();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Pattern")
    UDataTable* PatternTable = nullptr;

    /** Returns the ID of the next card to play. */
    UFUNCTION(BlueprintCallable, Category="Pattern")
    FName PickNextCard();

protected:
    virtual void BeginPlay() override;

private:
    FName LastCard;
    int32 RepeatCount = 0;
};
