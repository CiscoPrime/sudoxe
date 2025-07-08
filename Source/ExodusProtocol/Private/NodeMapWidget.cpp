#include "NodeMapWidget.h"
#include "NodeActor.h"
#include "ShopWidget.h"
#include "StoryEventWidget.h"
#include "ShopTypes.h"
#include "StoryEventTypes.h"
#include "Engine/DataTable.h"
#include "SaveSubsystem.h"

void UNodeMapWidget::InitWithNodes(const TArray<ANodeActor*>& Nodes)
{
    MapNodes = Nodes;
}

void UNodeMapWidget::HandleNodeActivated(ANodeActor* Node)
{
    if (!Node) { return; }

    const FEncounterNodeData& Data = Node->NodeData;

    switch (Data.NodeType)
    {
        case ENodeType::Shop:
        {
            if (ShopDataTable && !Data.PayloadID.IsNone())
            {
                const FShopData* Row = ShopDataTable->FindRow<FShopData>(Data.PayloadID, TEXT("HandleNodeActivated"));
                if (Row)
                {
                    TSubclassOf<UShopWidget> WidgetClass = ShopWidgetClass ? ShopWidgetClass : UShopWidget::StaticClass();
                    if (UShopWidget* Widget = CreateWidget<UShopWidget>(GetWorld(), WidgetClass))
                    {
                        Widget->InitWithData(*Row);
                        Widget->AddToViewport();
                    }
                }
            }
            break;
        }
        case ENodeType::Story:
        {
            if (StoryEventTable && !Data.PayloadID.IsNone())
            {
                const FStoryEventData* Row = StoryEventTable->FindRow<FStoryEventData>(Data.PayloadID, TEXT("HandleNodeActivated"));
                if (Row)
                {
                    TSubclassOf<UStoryEventWidget> WidgetClass = StoryEventWidgetClass ? StoryEventWidgetClass : UStoryEventWidget::StaticClass();
                    if (UStoryEventWidget* Widget = CreateWidget<UStoryEventWidget>(GetWorld(), WidgetClass))
                    {
                        Widget->InitWithData(*Row);
                        Widget->AddToViewport();
                    }
                }
            }
            break;
        }
        default:
            break;
    }

    if (UGameInstance* GI = GetGameInstance())
    {
        if (USaveSubsystem* Subsystem = GI->GetSubsystem<USaveSubsystem>())
        {
            USaveGame_RunState* State = Subsystem->LoadRunState();
            if (!State)
            {
                State = NewObject<USaveGame_RunState>();
            }
            Subsystem->SaveRunState(State);
        }
    }
}
