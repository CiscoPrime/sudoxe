#include "NodeMapWidget.h"
#include "NodeActor.h"

void UNodeMapWidget::InitWithNodes(const TArray<ANodeActor*>& Nodes)
{
    MapNodes = Nodes;
}
