#include "CardVisualComponent.h"
#include "CardComponent.h"
#include "CardActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"

UCardVisualComponent::UCardVisualComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UCardVisualComponent::BeginPlay()
{
    Super::BeginPlay();

    if (ACardActor* OwnerCard = Cast<ACardActor>(GetOwner()))
    {
        if (OwnerCard->CardComponent)
        {
            VisualData = OwnerCard->CardComponent->CardData.Visual;
        }
    }

    if (VisualData.SkeletalMesh)
    {
        SkeletalMeshComponent = NewObject<USkeletalMeshComponent>(GetOwner());
        if (SkeletalMeshComponent)
        {
            SkeletalMeshComponent->SetupAttachment(this);
            SkeletalMeshComponent->SetSkeletalMesh(VisualData.SkeletalMesh);
            SkeletalMeshComponent->RegisterComponent();
        }
    }
    else if (VisualData.Flipbook)
    {
        FlipbookComponent = NewObject<UPaperFlipbookComponent>(GetOwner());
        if (FlipbookComponent)
        {
            FlipbookComponent->SetupAttachment(this);
            FlipbookComponent->SetFlipbook(VisualData.Flipbook);
            FlipbookComponent->RegisterComponent();
        }
    }
    else if (VisualData.Sprite)
    {
        SpriteComponent = NewObject<UPaperSpriteComponent>(GetOwner());
        if (SpriteComponent)
        {
            SpriteComponent->SetupAttachment(this);
            SpriteComponent->SetSprite(VisualData.Sprite);
            SpriteComponent->RegisterComponent();
        }
    }

    PlayIdle();
}

void UCardVisualComponent::PlayAnimation(UAnimationAsset* Anim, bool bLoop)
{
    if (!Anim)
    {
        return;
    }

    if (SkeletalMeshComponent)
    {
        SkeletalMeshComponent->PlayAnimation(Anim, bLoop);
    }
    else if (FlipbookComponent)
    {
        if (UPaperFlipbook* Flip = Cast<UPaperFlipbook>(Anim))
        {
            FlipbookComponent->SetFlipbook(Flip);
        }
    }
}

void UCardVisualComponent::PlayIdle()
{
    PlayAnimation(VisualData.IdleAnimation, true);
}

void UCardVisualComponent::PlayAttack()
{
    PlayAnimation(VisualData.AttackAnimation, false);
}

void UCardVisualComponent::PlayDefend()
{
    PlayAnimation(VisualData.DefendAnimation, false);
}

void UCardVisualComponent::PlayWalk()
{
    PlayAnimation(VisualData.WalkAnimation, true);
}

void UCardVisualComponent::PlayRetreat()
{
    PlayAnimation(VisualData.RetreatAnimation, false);
}
