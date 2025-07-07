#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EventRouter.h"
#include "HUDWidget.generated.h"

/**
 * Root HUD widget that binds to the global EventRouter so Blueprint UI can react
 * to gameplay events.
 */
UCLASS()
class EXODUSPROTOCOL_API UHUDWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

protected:
    UFUNCTION(BlueprintImplementableEvent, Category="HUD")
    void OnCardPlayed(const FCardData& CardData);

    UFUNCTION(BlueprintImplementableEvent, Category="HUD")
    void OnDamageTaken(AActor* Target, int32 Amount);

    UFUNCTION(BlueprintImplementableEvent, Category="HUD")
    void OnActorDied(AActor* DeadActor);

private:
    UFUNCTION()
    void HandleCardPlayed(const FCardData& CardData);

    UFUNCTION()
    void HandleDamageTaken(AActor* Target, int32 Amount);

    UFUNCTION()
    void HandleActorDied(AActor* DeadActor);

    UPROPERTY()
    TObjectPtr<UEventRouter> CachedRouter = nullptr;
};

