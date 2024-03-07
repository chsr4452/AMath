// Fill out your copyright notice in the Description page of Project Settings.


#include "Aura/Public/Characters/Enemy/EnemyCharacter.h"

#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	AuraAbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AuraAbilitySystemComponent");
	AuraAbilitySystemComponent->SetIsReplicated(true);
	
	AuraAttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AuraAttributeSet");


}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
    		AuraAbilitySystemComponent->InitAbilityActorInfo(this, this);
	
	
}
