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

void ACardActor::BeginPlay()
{
    Super::BeginPlay();

    if (CardComponent)
    {
        CardComponent->OnDraw.AddDynamic(this, &ACardActor::HandleDraw);
        CardComponent->OnPlay.AddDynamic(this, &ACardActor::HandlePlay);
        CardComponent->OnResolve.AddDynamic(this, &ACardActor::HandleResolve);
        CardComponent->OnDiscard.AddDynamic(this, &ACardActor::HandleDiscard);
    }
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
            bResolvedBeforeDiscard = true;
        }
        CardComponent->TriggerDiscard();
        bResolvedBeforeDiscard = false;
    }
}

void ACardActor::HandleDraw()
{
    PlayIdle();
    OnCardDrawn();
}

void ACardActor::HandlePlay()
{
    PlayAttack();
    OnCardPlayed();
}

void ACardActor::HandleResolve()
{
    PlayRetreat();
    OnCardResolved();
}

void ACardActor::HandleDiscard()
{
    if (!bResolvedBeforeDiscard)
    {
        PlayRetreat();
    }
    OnCardDiscarded();
}

void ACardActor::PlayAttack()
{
    if (CardVisual)
    {
        CardVisual->PlayAttack();
    }
    OnAttack();
}

void ACardActor::PlayDefend()
{
    if (CardVisual)
    {
        CardVisual->PlayDefend();
    }
    OnDefend();
}

void ACardActor::PlayWalk()
{
    if (CardVisual)
    {
        CardVisual->PlayWalk();
    }
    OnWalk();
}

void ACardActor::PlayRetreat()
{
    if (CardVisual)
    {
        CardVisual->PlayRetreat();
    }
    OnRetreat();
}

void ACardActor::PlayIdle()
{
    if (CardVisual)
    {
        CardVisual->PlayIdle();
    }
}
