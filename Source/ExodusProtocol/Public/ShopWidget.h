#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopTypes.h"
#include "ShopWidget.generated.h"

/** Widget that displays shop items and handles purchases. */
UCLASS()
class EXODUSPROTOCOL_API UShopWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    /** Initialize the widget with the provided shop data. */
    UFUNCTION(BlueprintCallable, Category="Shop")
    void InitWithData(const FShopData& Data);

protected:
    /** Items available in this shop. */
    UPROPERTY(BlueprintReadOnly, Category="Shop")
    FShopData ShopData;

    /** Called when the player purchases an item. */
    UFUNCTION(BlueprintImplementableEvent, Category="Shop")
    void OnItemPurchased(const FShopItemData& Item);
};
