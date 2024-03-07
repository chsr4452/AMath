// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/AuraPlayerState.h"

#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	NetUpdateFrequency = 100;
	AuraAbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AuraAbilitySystemComponent");
	AuraAbilitySystemComponent->SetIsReplicated(true);
	AuraAbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AuraAttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AuraAttributeSet");

	if(AuraAttributeSet)
	{
		AuraAttributeSet->InitHealth(50);
		AuraAttributeSet->InitMaxHealth(100);
		AuraAttributeSet->InitMana(50);
		AuraAttributeSet->InitMaxMana(100);
	}
}

UAuraAttributeSet* AAuraPlayerState::GetAttributeSet()
{
	return AuraAttributeSet;
}
