// Copyright George R Sangillo


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthUpdated.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthUpdated.Broadcast(AuraAttributeSet->GetMaxHealth());

	OnManaUpdated.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaUpdated.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacks()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthUpdated);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthUpdated);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaUpdated);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaUpdated);
}

void UOverlayWidgetController::HealthUpdated(const FOnAttributeChangeData& Data) const
{
	OnHealthUpdated.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthUpdated(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthUpdated.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaUpdated(const FOnAttributeChangeData& Data) const
{
	OnManaUpdated.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaUpdated(const FOnAttributeChangeData& Data) const
{
	OnMaxManaUpdated.Broadcast(Data.NewValue);
}
