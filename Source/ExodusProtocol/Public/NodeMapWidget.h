#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h"
#include "NodeMapWidget.generated.h"

class ANodeActor;
class UShopWidget;
class UStoryEventWidget;

/** Widget that displays and interacts with map nodes. */
UCLASS()
class EXODUSPROTOCOL_API UNodeMapWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    /** Provide the set of nodes available on the map. */
    UFUNCTION(BlueprintCallable, Category="Map")
    void InitWithNodes(const TArray<ANodeActor*>& Nodes);

    /** Called when a node has been activated by the player. */
    UFUNCTION(BlueprintCallable, Category="Map")
    void HandleNodeActivated(ANodeActor* Node);

    /** Called when the player selects a node. */
    UFUNCTION(BlueprintImplementableEvent, Category="Map")
    void OnNodeSelected(ANodeActor* SelectedNode);

protected:
    UPROPERTY(BlueprintReadOnly, Category="Map")
    TArray<ANodeActor*> MapNodes;

    /** Data table containing shop definitions. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Map")
    UDataTable* ShopDataTable = nullptr;

    /** Data table containing story events. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Map")
    UDataTable* StoryEventTable = nullptr;

    /** Widget class used to present shop UIs. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Map")
    TSubclassOf<UShopWidget> ShopWidgetClass;

    /** Widget class used to present story events. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Map")
    TSubclassOf<UStoryEventWidget> StoryEventWidgetClass;
};
