//=== EventRouter.cpp ======================================================
#include "EventRouter.h"
#include "Kismet/GameplayStatics.h"
#include "CoreGameMode.h"

UEventRouter* UEventRouter::Get(const UObject* WorldContext)
{
    if (!WorldContext) { return nullptr; }

    if (const UWorld* World = WorldContext->GetWorld())
    {
        if (ACoreGameMode* GM = World->GetAuthGameMode<ACoreGameMode>())
        {
            return GM->GetEventRouter();
        }
    }
    return nullptr;
}
