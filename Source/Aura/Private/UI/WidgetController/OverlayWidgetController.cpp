// Copyright George R Sangillo


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthUpdated.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthUpdated.Broadcast(AuraAttributeSet->GetMaxHealth());
}
