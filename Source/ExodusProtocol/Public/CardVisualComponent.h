#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CardTypes.h"
#include "CardVisualComponent.generated.h"

class USkeletalMeshComponent;
class UPaperFlipbookComponent;
class UPaperSpriteComponent;
class ACardActor;

/** Spawns visual assets for a card and plays animations. */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EXODUSPROTOCOL_API UCardVisualComponent : public USceneComponent
{
    GENERATED_BODY()
public:
    UCardVisualComponent();

    /** Play idle animation. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayIdle();

    /** Play attack animation. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayAttack();

    /** Play defend animation. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayDefend();

    /** Play walk animation. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayWalk();

    /** Play retreat animation. */
    UFUNCTION(BlueprintCallable, Category="Card|Visual")
    void PlayRetreat();

protected:
    virtual void BeginPlay() override;

private:
    void PlayAnimation(UAnimationAsset* Anim, bool bLoop);

    FCardVisualData VisualData;

    UPROPERTY()
    TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent = nullptr;

    UPROPERTY()
    TObjectPtr<UPaperFlipbookComponent> FlipbookComponent = nullptr;

    UPROPERTY()
    TObjectPtr<UPaperSpriteComponent> SpriteComponent = nullptr;
};
