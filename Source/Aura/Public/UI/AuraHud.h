// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHud.generated.h"

/**
 * 
 */
class UAuraOverlayWidget;
UCLASS()
class AURA_API AAuraHud : public AHUD
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	TObjectPtr<UUserWidget> OverlayWidget;
protected:
	UPROPERTY(EditAnywhere, Category = "Widget Class")
	TSubclassOf<UUserWidget> OverlayWidgetClass;
	
};
