#include "CardActor.h"
#include "Components/SceneComponent.h"

ACardActor::ACardActor()
{
    PrimaryActorTick.bCanEverTick = false;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    CardComponent = CreateDefaultSubobject<UCardComponent>(TEXT("CardComponent"));
    CardVisual = CreateDefaultSubobject<UCardVisualComponent>(TEXT("CardVisual"));
    CardVisual->SetupAttachment(RootComponent);
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
        if (CardVisual)
        {
            CardVisual->PlayIdle();
        }
    }
    else if (OldZone == ECardZone::Hand && NewZone == ECardZone::Queue)
    {
        CardComponent->TriggerPlay();
        if (CardVisual)
        {
            CardVisual->PlayAttack();
        }
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
            if (CardVisual)
            {
                CardVisual->PlayRetreat();
            }
        }
        else if (CardVisual)
        {
            CardVisual->PlayRetreat();
        }
        CardComponent->TriggerDiscard();
    }
}
