// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttrChange, float, value);

UCLASS(Blueprintable, BlueprintType)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	void BroadCastInitialValues() override;
	void BindCallbackToDependencies() override;

	UPROPERTY(BlueprintAssignable)
	FOnAttrChange OnHealthChange;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttrChange OnMaxHealthChange;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttrChange OnManaChange;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttrChange OnMaxManaChange;
};
