// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"


class UOverlayWidgetController;
class UAuraAbilitySystemComponent;
class UAuraAttributeSet;
class UAuraUserWidget;
class UAuraWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void InitOverlay(UAuraAttributeSet* AS, UAuraAbilitySystemComponent* ASC);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget")
	TSubclassOf<UUserWidget>  OverlayWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Widget")
	TSubclassOf<UOverlayWidgetController>  OverlayWidgetControllerClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UOverlayWidgetController>  OverlayWidgetController;	
};
