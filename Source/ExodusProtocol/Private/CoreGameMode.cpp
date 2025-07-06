//=== CoreGameMode.cpp =====================================================
#include "CoreGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "EventRouter.h"

ACoreGameMode::ACoreGameMode()
{
    // You can set default pawn, HUD, etc. here if desired.
}

void ACoreGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (EventRouterClass)
    {
        EventRouter = NewObject<UEventRouter>(this, EventRouterClass);
        if (EventRouter)
        {
            EventRouter->AddToRoot(); // ensure it isn’t garbage-collected
        }
    }
}
