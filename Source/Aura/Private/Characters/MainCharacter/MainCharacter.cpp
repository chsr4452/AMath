﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Aura/Public/Characters/MainCharacter/MainCharacter.h"

#include "Camera/CameraComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"
#include "PlayerState/AuraPlayerState.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
	bReplicates = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	
	
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->TargetArmLength = 1000;
	SpringArmComponent->bInheritPitch = 0;
	SpringArmComponent->bInheritYaw = 0;
	SpringArmComponent->bInheritRoll = 0;

	
	SpringArmComponent->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	if(AuraAttributeSet)
	{
			AuraAttributeSet->InitHealth(50);
        	AuraAttributeSet->InitMaxHealth(100);
        	AuraAttributeSet->InitMana(50);
        	AuraAttributeSet->InitMaxMana(100);
	}

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMainCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfoAura();
}

void AMainCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfoAura();
}

void AMainCharacter::InitAbilityActorInfoAura()
{
	if(AAuraPlayerState* PS= Cast<AAuraPlayerState>(GetPlayerState()))
	{
		AuraAbilitySystemComponent = Cast<UAuraAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(PS));
		check(AuraAbilitySystemComponent);
		AuraAttributeSet = PS->GetAttributeSet();
		AuraAbilitySystemComponent->InitAbilityActorInfo(PS, this);
	}
}
