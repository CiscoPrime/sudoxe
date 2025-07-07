#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NodeMapWidget.generated.h"

class ANodeActor;

/** Widget that displays and interacts with map nodes. */
UCLASS()
class EXODUSPROTOCOL_API UNodeMapWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    /** Provide the set of nodes available on the map. */
    UFUNCTION(BlueprintCallable, Category="Map")
    void InitWithNodes(const TArray<ANodeActor*>& Nodes);

    /** Called when the player selects a node. */
    UFUNCTION(BlueprintImplementableEvent, Category="Map")
    void OnNodeSelected(ANodeActor* SelectedNode);

protected:
    UPROPERTY(BlueprintReadOnly, Category="Map")
    TArray<ANodeActor*> MapNodes;
};
