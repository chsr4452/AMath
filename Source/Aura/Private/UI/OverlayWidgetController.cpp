// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OverlayWidgetController.h"

#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BindCallback()
{
	AuraAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).
	                            AddUObject(this, &UOverlayWidgetController::HealthChange);
}

void UOverlayWidgetController::HealthChange(const FOnAttributeChangeData& Data)
{
	OnHealthChange.Broadcast(Data.NewValue);
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Red, "Health Changed");
}
