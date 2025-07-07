//=== CardComponent.cpp =====================================================
#include "CardComponent.h"

#include "GameFramework/Actor.h"

UCardComponent::UCardComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCardComponent::SetCardData(const FCardData& Data)
{
    CardData = Data;
}

void UCardComponent::PlayCard()
{
    if (UEventRouter* Router = UEventRouter::Get(this))
    {
        Router->OnCardPlayed.Broadcast(CardData);
    }
}
