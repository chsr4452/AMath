// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraHUD.h"

#include "UI/AuraHud.h"

#include "Blueprint/UserWidget.h"
#include "UI/AuraUserWidget.h"
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
		checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass does not set up"));
		checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass does not set up"));
		FControllerParams ControllParams = FControllerParams(AS, ASC, PC, PS);
		OverlayWidgetController = GetWidgetController(ControllParams);
	
    	UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
		OverlayWidget = Cast<UAuraUserWidget>(UserWidget);
		OverlayWidget->SetWidgetController(OverlayWidgetController);
		OverlayWidgetController->BroadCastInitialValues();
		OverlayWidgetController->BindCallbackToDependencies();
    	OverlayWidget->AddToViewport();
	// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "InitOverlayWidget");
    	
}


