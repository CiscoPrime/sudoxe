#include "Misc/AutomationTest.h"
#include "NodeMapWidget.h"
#include "NodeActor.h"
#include "SaveSubsystem.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FNodeActivationSavesVisitedTest,
    "ExodusProtocol.NodeMapWidget.HandleNodeActivated.SavesVisited",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FNodeActivationSavesVisitedTest::RunTest(const FString& Parameters)
{
    UGameInstance* GI = NewObject<UGameInstance>();
    UNodeMapWidget* Widget = NewObject<UNodeMapWidget>(GI);
    USaveSubsystem* Subsystem = GI->GetSubsystem<USaveSubsystem>();

    ANodeActor* Node = NewObject<ANodeActor>();
    Node->NodeData.NodeID = TEXT("TestNodeID");
    Node->NodeData.NodeType = ENodeType::Combat;

    Widget->HandleNodeActivated(Node);

    USaveGame_RunState* Loaded = Subsystem->LoadRunState();
    TestTrue(TEXT("RunState created"), Loaded != nullptr);
    if (Loaded)
    {
        TestTrue(TEXT("Visited contains ID"), Loaded->VisitedNodeIDs.Contains(Node->NodeData.NodeID));
    }

    Subsystem->DeleteSave();
    return true;
}
