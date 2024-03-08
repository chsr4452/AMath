// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "GameplayAbilitySystem/AuraAbilitySystemComponent.h"
#include "UI/AuraWidgetController.h"
#include "UI/OverlayWidgetController.h"


void AAuraHUD::InitOverlay(UAuraAttributeSet* AS, UAuraAbilitySystemComponent* ASC)
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
	}
	OverlayWidgetController->AuraAttributeSet = AS;
	OverlayWidgetController->AuraAbilitySystemComponent = ASC;
	
	if(OverlayWidgetController)
	{
		OverlayWidgetController->BindCallback();
	}
	
	Widget->AddToViewport();
}
