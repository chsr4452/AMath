// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

class UAuraWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UAuraWidgetController* WidgetController);

	UPROPERTY(BlueprintReadOnly, Category= "Widget")
	TObjectPtr<UAuraWidgetController> WidgetController;

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
