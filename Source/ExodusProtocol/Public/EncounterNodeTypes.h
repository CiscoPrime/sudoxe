//=== EncounterNodeTypes.h ================================================
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"          // optional tags
#include "EncounterNodeTypes.generated.h"  // keep last

/** What the player finds at this node. */
UENUM(BlueprintType)
enum class ENodeType : uint8
{
    Combat     UMETA(DisplayName = "Combat"),
    Elite      UMETA(DisplayName = "Elite"),
    Boss       UMETA(DisplayName = "Boss"),
    Shop       UMETA(DisplayName = "Shop"),
    Story      UMETA(DisplayName = "Story Event"),
    Rest       UMETA(DisplayName = "Rest Site")
};

/** Pure‑data row for the world‑map nodes. */
USTRUCT(BlueprintType)
struct FEncounterNodeData : public FTableRowBase
{
    GENERATED_BODY()

    /** Internal key (e.g. “Act1_Grunt”). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Node")
    FName NodeID = NAME_None;

    /** Friendly name on UI tooltips. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Node")
    FText DisplayName;

    /** Kind of content this node triggers. */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Node")
    ENodeType NodeType = ENodeType::Combat;

    /** Points to another DataTable row (enemy group, shop list, story entry…). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Node")
    FName PayloadID = NAME_None;

    /** Extra flag for map‑generation (“Early”, “Late”, etc.). */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Node")
    FGameplayTag NodeTag;
};
