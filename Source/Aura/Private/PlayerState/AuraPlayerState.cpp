// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/AuraPlayerState.h"

#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	NetUpdateFrequency = 100;
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	if(AuraAttributeSet)
	{
		AuraAttributeSet->InitHealth(50);
		AuraAttributeSet->InitMaxHealth(100);
		AuraAttributeSet->InitMana(100);
		AuraAttributeSet->InitMaxMana(100);
	}
}

UAttributeSet* AAuraPlayerState::GetAttributeSet()
{
	return AttributeSet;
}

