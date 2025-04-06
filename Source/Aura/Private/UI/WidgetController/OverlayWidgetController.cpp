// Copyright George R Sangillo


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthUpdated.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthUpdated.Broadcast(AuraAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacks()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthUpdated);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthUpdated);
}

void UOverlayWidgetController::HealthUpdated(const FOnAttributeChangeData& Data) const
{
	OnHealthUpdated.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthUpdated(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthUpdated.Broadcast(Data.NewValue);
}
