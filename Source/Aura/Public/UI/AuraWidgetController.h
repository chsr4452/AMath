// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AuraWidgetController.generated.h"

class UAuraAbilitySystemComponent;
class UAuraAttributeSet;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UAuraWidgetController();
	UPROPERTY(BlueprintReadWrite, Category = "Player Data")
	TObjectPtr<UAuraAttributeSet> AuraAttributeSet;

	UPROPERTY(BlueprintReadWrite, Category = "Player Data")
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;
};
