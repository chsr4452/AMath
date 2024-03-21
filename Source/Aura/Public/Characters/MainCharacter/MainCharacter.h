// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Aura/Public/Characters/AuraCharacterBase.h"
#include "MainCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class AURA_API AMainCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;
	
private:
	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void InitAbilityActorInfoAura();
};
