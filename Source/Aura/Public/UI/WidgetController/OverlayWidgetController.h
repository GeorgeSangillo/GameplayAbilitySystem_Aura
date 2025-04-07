// Copyright George R Sangillo

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthUpdatedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthUpdatedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaUpdatedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaUpdatedSignature, float, NewMaxMana);
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
	void HealthUpdated(const FOnAttributeChangeData& Data) const;
	void MaxHealthUpdated(const FOnAttributeChangeData& Data) const;
	void ManaUpdated(const FOnAttributeChangeData& Data) const;
	void MaxManaUpdated(const FOnAttributeChangeData& Data) const;
};
