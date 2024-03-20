// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OverlayWidgetController.h"

#include "GameplayAbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadCastInitialValues()
{
	OnHealthChange.Broadcast(GetAuraAS()->GetHealth());
	OnMaxHealthChange.Broadcast(GetAuraAS()->GetMaxHealth());
	OnManaChange.Broadcast(GetAuraAS()->GetMana());
	OnMaxManaChange.Broadcast(GetAuraAS()->GetMaxMana());
}

void UOverlayWidgetController::BindCallbackToDependencies()
{
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GetAuraAS()->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData &Data)
		{
			OnHealthChange.Broadcast(Data.NewValue);
		}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GetAuraAS()->GetManaAttribute()).AddLambda([this](const FOnAttributeChangeData &Data)
		{
			OnManaChange.Broadcast(Data.NewValue);
		}
		);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GetAuraAS()->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData &Data)
		{
			OnMaxHealthChange.Broadcast(Data.NewValue);
		}
		);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(GetAuraAS()->GetMaxManaAttribute()).AddLambda([this](const FOnAttributeChangeData &Data)
		{
			OnMaxManaChange.Broadcast(Data.NewValue);
		}
		);
}
