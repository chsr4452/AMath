// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraHud.h"

#include "Blueprint/UserWidget.h"
#include "UI/AuraWidgetController.h"
#include "UI/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetWidgetController(FControllerParams &ControllParams)
{
	if(OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(GetWorld(), OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetController(ControllParams);
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlayWidget(UAttributeSet* AS, UAbilitySystemComponent* ASC, APlayerController * PC, APlayerState* PS)
{
		FControllerParams ControllParams = FControllerParams(AS, ASC, PC, PS);
		OverlayWidgetController = GetWidgetController(ControllParams);
		if(OverlayWidgetClass)
    	{
    		OverlayWidget = CreateWidget(GetWorld(), OverlayWidgetClass);
    		OverlayWidget->AddToViewport();
    	}
}


