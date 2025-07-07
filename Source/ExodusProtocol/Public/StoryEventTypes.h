//=== StoryEventTypes.h =====================================================
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "StoryEventTypes.generated.h"

/** Player choice option within a story event. */
USTRUCT(BlueprintType)
struct FStoryChoice
{
    GENERATED_BODY();

    /** Text displayed for this choice. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Story")
    FText ChoiceText;

    /** ID of the payload triggered when chosen. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Story")
    FName PayloadID = NAME_None;
};

/** Row describing a full story event. */
USTRUCT(BlueprintType)
struct FStoryEventData : public FTableRowBase
{
    GENERATED_BODY();

    /** Unique identifier for this event. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Story")
    FName EventID = NAME_None;

    /** Intro snippet shown before choices. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Story")
    FText SnippetText;

    /** Choices presented to the player. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Story")
    TArray<FStoryChoice> Choices;
};
