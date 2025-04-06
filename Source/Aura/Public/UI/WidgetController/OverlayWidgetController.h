// Copyright George R Sangillo

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthUpdatedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthUpdatedSignature, float, NewMaxHealth);

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

protected:
	void HealthUpdated(const FOnAttributeChangeData& Data) const;
	void MaxHealthUpdated(const FOnAttributeChangeData& Data) const;
};
