#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StoryEventTypes.h"
#include "StoryEventWidget.generated.h"

/** Widget that presents a story event and handles player choices. */
UCLASS()
class EXODUSPROTOCOL_API UStoryEventWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    /** Initialize the widget with the provided story event data. */
    UFUNCTION(BlueprintCallable, Category="Story")
    void InitWithData(const FStoryEventData& Data);

protected:
    /** The event data driving this widget. */
    UPROPERTY(BlueprintReadOnly, Category="Story")
    FStoryEventData EventData;

    /** Called when the player selects a choice. */
    UFUNCTION(BlueprintImplementableEvent, Category="Story")
    void OnChoiceSelected(const FStoryChoice& Choice);
};
