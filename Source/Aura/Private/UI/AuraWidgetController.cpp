// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraWidgetController.h"

#include "Characters/MainCharacter/AuraPlayerController.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"
#include "PlayerState/AuraPlayerState.h"


void UAuraWidgetController::SetWidgetController(FControllerParams &ControllParams)
{

	AttributeSet = ControllParams.AttributeSet;
	
	AbilitySystemComponent = ControllParams.AbilitySystemComponent;
	
	PlayerController = ControllParams.PlayerController;
	
	PlayerState = ControllParams.PlayerState;
}

void UAuraWidgetController::BroadCastInitialValues()
{
}

void UAuraWidgetController::BindCallbackToDependencies()
{
}

UAuraAttributeSet* UAuraWidgetController::GetAuraAS()
{
	if(AuraAttributeSet == nullptr)
	{
		AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	}
	return AuraAttributeSet;
}

UAuraAbilitySystemComponent* UAuraWidgetController::GetAuraASC()
{
	if(AuraAbilitySystemComponent == nullptr)
	{
		AuraAbilitySystemComponent = Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent);
	}
	return AuraAbilitySystemComponent;
}

AAuraPlayerController* UAuraWidgetController::GetAuraPC()
{
	if(AuraPlayerController == nullptr)
	{
		AuraPlayerController = Cast<AAuraPlayerController>(AuraPlayerController);
	}
	return AuraPlayerController;
}

AAuraPlayerState* UAuraWidgetController::GetAuraPS()
{
	if(AuraPlayerState == nullptr)
	{
		AuraPlayerState = Cast<AAuraPlayerState>(PlayerState);
	}
	return AuraPlayerState;
}

UAuraWidgetController::UAuraWidgetController()
{
}
