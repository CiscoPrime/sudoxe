#include "GameHUD.h"
#include "HUDWidget.h"
#include "Blueprint/UserWidget.h"
#include "Engine/World.h"

void AGameHUD::BeginPlay()
{
    Super::BeginPlay();

    if (HUDWidgetClass)
    {
        HUDWidget = CreateWidget<UHUDWidget>(GetWorld(), HUDWidgetClass);
        if (HUDWidget)
        {
            HUDWidget->AddToViewport();
        }
    }
}
