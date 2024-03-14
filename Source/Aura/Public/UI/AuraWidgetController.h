// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "UObject/Object.h"
#include "AuraWidgetController.generated.h"

class AAuraPlayerState;
class AAuraPlayerController;
class UAuraAbilitySystemComponent;
class UAttributeSet;

class UAuraAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FControllerParams
{
	GENERATED_BODY()
	FControllerParams(){}
	
	FControllerParams(UAttributeSet* AS, UAbilitySystemComponent* ASC, APlayerController * PC, APlayerState* PS):
	AttributeSet(AS), AbilitySystemComponent(ASC), PlayerController(PC), PlayerState(PS){}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState;
};
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UAuraWidgetController();
	
	void SetWidgetController(FControllerParams &ControllParams);
	virtual void BroadCastInitialValues();
	virtual void BindCallbackToDependencies();

	UFUNCTION()
	UAuraAttributeSet* GetAuraAS();
	
	UFUNCTION()
	UAuraAbilitySystemComponent* GetAuraASC();
	
	UFUNCTION()
	AAuraPlayerController* GetAuraPC();
	
	UFUNCTION()
	AAuraPlayerState* GetAuraPS();
	
protected:
	//base class
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState;
	
	//Aura class
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAuraAttributeSet> AuraAttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AAuraPlayerController> AuraPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AAuraPlayerState> AuraPlayerState;
};
