// Copyright George R Sangillo

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

class UAuraUserWidget;

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthUpdatedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthUpdatedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaUpdatedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaUpdatedSignature, float, NewMaxMana);

USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	FText Message = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UAuraUserWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacks() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthUpdatedSignature OnHealthUpdated;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthUpdatedSignature OnMaxHealthUpdated;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnManaUpdatedSignature OnManaUpdated;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnManaUpdatedSignature OnMaxManaUpdated;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Widget Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable;

	void HealthUpdated(const FOnAttributeChangeData& Data) const;
	void MaxHealthUpdated(const FOnAttributeChangeData& Data) const;
	void ManaUpdated(const FOnAttributeChangeData& Data) const;
	void MaxManaUpdated(const FOnAttributeChangeData& Data) const;
};
