// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraUserWidget.h"



void UAuraUserWidget::SetWidgetController(UAuraWidgetController* WidgetControllerInput)
{
	WidgetController = WidgetControllerInput;
	WidgetControllerSet();
	// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "WidgetControllerSet Event");
}
