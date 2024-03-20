// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;
class UAbilitySystemComponent;
class UAttributeSet;
struct FControllerParams;
class UAuraWidgetController;
/**
 * 
 */
class UAuraOverlayWidget;
class UOverlayWidgetController;
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	UOverlayWidgetController* GetWidgetController(FControllerParams &ControllParams);

	void InitOverlayWidget(UAttributeSet* AS, UAbilitySystemComponent* ASC, APlayerController * PC, APlayerState* PS);
	
protected:
	UPROPERTY(EditAnywhere, Category = "Widget Class")
	TSubclassOf<UUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Widget Class")
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere, Category = "Widget Class")
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
