#include "NodeActor.h"

ANodeActor::ANodeActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

TArray<ANodeActor*> ANodeActor::GetNeighbours() const
{
    return Neighbours;
}
