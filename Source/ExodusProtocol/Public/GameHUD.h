#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

class UHUDWidget;

/** Simple HUD actor that adds a UHUDWidget to the viewport at BeginPlay. */
UCLASS()
class EXODUSPROTOCOL_API AGameHUD : public AHUD
{
    GENERATED_BODY()
protected:
    virtual void BeginPlay() override;

    /** Widget class that will be created and added to the viewport. */
    UPROPERTY(EditDefaultsOnly, Category="HUD")
    TSubclassOf<UHUDWidget> HUDWidgetClass;

    /** Live widget instance created at runtime. */
    UPROPERTY()
    TObjectPtr<UHUDWidget> HUDWidget = nullptr;
};
