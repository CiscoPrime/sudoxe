#include "CardActor.h"

ACardActor::ACardActor()
{
    PrimaryActorTick.bCanEverTick = false;

    CardComponent = CreateDefaultSubobject<UCardComponent>(TEXT("CardComponent"));
    RootComponent = CardComponent;
}

void ACardActor::MoveToZone(ECardZone NewZone)
{
    if (CardZone == NewZone)
    {
        return;
    }

    const ECardZone OldZone = CardZone;
    CardZone = NewZone;

    if (!CardComponent)
    {
        return;
    }

    if (OldZone == ECardZone::DrawPile && NewZone == ECardZone::Hand)
    {
        CardComponent->TriggerDraw();
    }
    else if (OldZone == ECardZone::Hand && NewZone == ECardZone::Queue)
    {
        CardComponent->TriggerPlay();
        if (UEventRouter* Router = UEventRouter::Get(this))
        {
            Router->OnCardPlayed.Broadcast(CardComponent->CardData);
        }
    }

    if (NewZone == ECardZone::Grave)
    {
        if (OldZone == ECardZone::Queue)
        {
            CardComponent->TriggerResolve();
        }
        CardComponent->TriggerDiscard();
    }
}
