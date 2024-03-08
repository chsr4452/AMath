// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraUserWidget.h"
#include "HealthGlobeWidget.generated.h"

class UProgressBar;
/**
 * @class UHealthGlobeWidget
 *
 * The UHealthGlobeWidget class represents a widget that displays a health globe with a progress bar.
 */
UCLASS()
class AURA_API UHealthGlobeWidget : public UAuraUserWidget
{
	GENERATED_BODY()
	UHealthGlobeWidget();
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* MyProgressBar;
};
