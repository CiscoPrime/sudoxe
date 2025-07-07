#include "HUDWidget.h"
#include "EventRouter.h"

void UHUDWidget::NativeConstruct()
{
    Super::NativeConstruct();

    CachedRouter = UEventRouter::Get(this);
    if (CachedRouter)
    {
        CachedRouter->OnCardPlayed.AddDynamic(this, &UHUDWidget::HandleCardPlayed);
        CachedRouter->OnDamageTaken.AddDynamic(this, &UHUDWidget::HandleDamageTaken);
        CachedRouter->OnActorDied.AddDynamic(this, &UHUDWidget::HandleActorDied);
    }
}

void UHUDWidget::NativeDestruct()
{
    if (CachedRouter)
    {
        CachedRouter->OnCardPlayed.RemoveDynamic(this, &UHUDWidget::HandleCardPlayed);
        CachedRouter->OnDamageTaken.RemoveDynamic(this, &UHUDWidget::HandleDamageTaken);
        CachedRouter->OnActorDied.RemoveDynamic(this, &UHUDWidget::HandleActorDied);
        CachedRouter = nullptr;
    }
    Super::NativeDestruct();
}

void UHUDWidget::HandleCardPlayed(const FCardData& CardData)
{
    OnCardPlayed(CardData);
}

void UHUDWidget::HandleDamageTaken(AActor* Target, int32 Amount)
{
    OnDamageTaken(Target, Amount);
}

void UHUDWidget::HandleActorDied(AActor* DeadActor)
{
    OnActorDied(DeadActor);
}

