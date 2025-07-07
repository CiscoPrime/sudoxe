#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EncounterNodeTypes.h"
#include "NodeActor.generated.h"

/** Simple map node actor used on the world map. */
UCLASS()
class EXODUSPROTOCOL_API ANodeActor : public AActor
{
    GENERATED_BODY()
public:
    ANodeActor();

    /** Data describing this node's encounter. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
    FEncounterNodeData NodeData;

    /** Adjacent nodes reachable from this one. */
    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="Node")
    TArray<ANodeActor*> Neighbours;

    /** Return connected neighbour nodes. */
    UFUNCTION(BlueprintCallable, Category="Node")
    TArray<ANodeActor*> GetNeighbours() const;
};
