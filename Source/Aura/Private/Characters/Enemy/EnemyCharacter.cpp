// Fill out your copyright notice in the Description page of Project Settings.


#include "Aura/Public/Characters/Enemy/EnemyCharacter.h"
#include "AbilitySystemComponent.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");


}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
    		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
	
}
