#include "Misc/AutomationTest.h"
#include "SaveSubsystem.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSaveSubsystemRoundTrip, "ExodusProtocol.SaveSubsystem.SaveLoad", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FSaveSubsystemRoundTrip::RunTest(const FString& Parameters)
{
    USaveSubsystem* Subsys = NewObject<USaveSubsystem>();
    USaveGame_RunState* Saved = NewObject<USaveGame_RunState>();
    Saved->DeckCardIDs = { FName("C1"), FName("C2") };
    Saved->VisitedNodeIDs = { FName("N1"), FName("N2") };

    TestTrue(TEXT("Save success"), Subsys->SaveRunState(Saved));

    USaveGame_RunState* Loaded = Subsys->LoadRunState();
    TestTrue(TEXT("Loaded not null"), Loaded != nullptr);
    if (Loaded)
    {
        TestEqual(TEXT("Deck count"), Loaded->DeckCardIDs.Num(), Saved->DeckCardIDs.Num());
        for (int32 i = 0; i < Saved->DeckCardIDs.Num(); ++i)
        {
            TestEqual(FString::Printf(TEXT("DeckID %d"), i), Loaded->DeckCardIDs[i], Saved->DeckCardIDs[i]);
        }
        TestEqual(TEXT("Visited count"), Loaded->VisitedNodeIDs.Num(), Saved->VisitedNodeIDs.Num());
        for (int32 i = 0; i < Saved->VisitedNodeIDs.Num(); ++i)
        {
            TestEqual(FString::Printf(TEXT("NodeID %d"), i), Loaded->VisitedNodeIDs[i], Saved->VisitedNodeIDs[i]);
        }
    }

    Subsys->DeleteSave();
    return true;
}

