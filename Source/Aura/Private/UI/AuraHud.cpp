// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraHud.h"

#include "Blueprint/UserWidget.h"

void AAuraHud::BeginPlay()
{
	Super::BeginPlay();
	if(OverlayWidgetClass)
	{
		OverlayWidget = CreateWidget(GetWorld(), OverlayWidgetClass);
		OverlayWidget->AddToViewport();
	}
	
	
	
}
