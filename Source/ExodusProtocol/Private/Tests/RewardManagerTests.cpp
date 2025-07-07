#include "Misc/AutomationTest.h"
#include "RewardManager.h"
#include "Engine/DataTable.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGetRandomCardsTest, "ExodusProtocol.RewardManager.GetRandomCards.Deterministic", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGetRandomCardsTest::RunTest(const FString& Parameters)
{
    URewardManager* Manager = NewObject<URewardManager>();
    Manager->RandomStream.Initialize(12345);

    UDataTable* CardTable = NewObject<UDataTable>();
    CardTable->RowStruct = FCardData::StaticStruct();
    Manager->CardTable = CardTable;

    FCardData RowA; RowA.CardID = TEXT("A");
    FCardData RowB; RowB.CardID = TEXT("B");
    FCardData RowC; RowC.CardID = TEXT("C");
    CardTable->AddRow(FName("A"), RowA);
    CardTable->AddRow(FName("B"), RowB);
    CardTable->AddRow(FName("C"), RowC);

    TArray<FCardData> First = Manager->GetRandomCards(2, FGameplayTag());
    Manager->RandomStream.Initialize(12345);
    TArray<FCardData> Second = Manager->GetRandomCards(2, FGameplayTag());

    TestEqual(TEXT("Same number of cards"), First.Num(), Second.Num());
    for (int32 i = 0; i < First.Num(); ++i)
    {
        TestEqual(FString::Printf(TEXT("CardID %d"), i), First[i].CardID, Second[i].CardID);
    }
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGetDeckCardIDsTest, "ExodusProtocol.RewardManager.GetDeckCardIDs", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FGetDeckCardIDsTest::RunTest(const FString& Parameters)
{
    URewardManager* Manager = NewObject<URewardManager>();

    UDataTable* DeckTable = NewObject<UDataTable>();
    DeckTable->RowStruct = FDeckData::StaticStruct();
    Manager->DeckTable = DeckTable;

    FDeckData Deck; Deck.DeckID = TEXT("Start");
    Deck.CardIDs.Add(FName("C1"));
    Deck.CardIDs.Add(FName("C2"));
    DeckTable->AddRow(FName("Start"), Deck);

    TArray<FName> IDs = Manager->GetDeckCardIDs("Start");
    TestEqual(TEXT("Deck size"), IDs.Num(), Deck.CardIDs.Num());
    for (int32 i = 0; i < Deck.CardIDs.Num(); ++i)
    {
        TestEqual(FString::Printf(TEXT("CardID %d"), i), IDs[i], Deck.CardIDs[i]);
    }

    TArray<FName> Empty = Manager->GetDeckCardIDs("Missing");
    TestEqual(TEXT("Invalid deck is empty"), Empty.Num(), 0);
    return true;
}
