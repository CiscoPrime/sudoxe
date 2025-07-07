#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardWidget.generated.h"

class UCardComponent;

/** UI widget that displays a card and reacts to lifecycle events. */
UCLASS()
class EXODUSPROTOCOL_API UCardWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    /** Bind this widget to a card component so it reacts to events. */
    UFUNCTION(BlueprintCallable, Category="Card")
    void InitWithComponent(UCardComponent* Component);

protected:
    UPROPERTY(BlueprintReadOnly, Category="Card")
    TObjectPtr<UCardComponent> CardComponent = nullptr;

    UFUNCTION(BlueprintImplementableEvent, Category="Card")
    void OnCardDrawn();

    UFUNCTION(BlueprintImplementableEvent, Category="Card")
    void OnCardPlayed();

    UFUNCTION(BlueprintImplementableEvent, Category="Card")
    void OnCardResolved();

    UFUNCTION(BlueprintImplementableEvent, Category="Card")
    void OnCardDiscarded();

private:
    UFUNCTION()
    void HandleDraw();

    UFUNCTION()
    void HandlePlay();

    UFUNCTION()
    void HandleResolve();

    UFUNCTION()
    void HandleDiscard();
};
