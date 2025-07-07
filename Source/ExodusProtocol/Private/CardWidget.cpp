#include "CardWidget.h"
#include "CardComponent.h"

void UCardWidget::InitWithComponent(UCardComponent* Component)
{
    if (!Component)
    {
        return;
    }

    CardComponent = Component;
    Component->OnDraw.AddDynamic(this, &UCardWidget::HandleDraw);
    Component->OnPlay.AddDynamic(this, &UCardWidget::HandlePlay);
    Component->OnResolve.AddDynamic(this, &UCardWidget::HandleResolve);
    Component->OnDiscard.AddDynamic(this, &UCardWidget::HandleDiscard);
}

void UCardWidget::HandleDraw()
{
    OnCardDrawn();
}

void UCardWidget::HandlePlay()
{
    OnCardPlayed();
}

void UCardWidget::HandleResolve()
{
    OnCardResolved();
}

void UCardWidget::HandleDiscard()
{
    OnCardDiscarded();
}
