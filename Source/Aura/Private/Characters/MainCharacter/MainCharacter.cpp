// Fill out your copyright notice in the Description page of Project Settings.


#include "Aura/Public/Characters/MainCharacter/MainCharacter.h"

#include "Camera/CameraComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Characters/MainCharacter/AuraPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"
#include "PlayerState/AuraPlayerState.h"
#include "UI/AuraHUD.h"


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
	APlayerState* PS = GetPlayerState();
	if(AAuraPlayerState* AuraPS = Cast<AAuraPlayerState>(PS))
	{
		AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(PS);
		check(AbilitySystemComponent);
		AttributeSet = Cast<AAuraPlayerState>(PS)->GetAttributeSet();
		AbilitySystemComponent->InitAbilityActorInfo(PS, this);
		if(APlayerController* PC = PS->GetPlayerController())
		{
			AAuraHUD* AuraHUD = Cast<AAuraHUD>(PC->GetHUD());
			if(AuraHUD)
			{
				AuraHUD->InitOverlayWidget(AttributeSet, AbilitySystemComponent, PC, PS);
			}
		}

	}
}


// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();



}


