// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AuraAnimInstanceBase.generated.h"

class AAuraCharacterBase;
/**
 * 
 */
UCLASS()
class AURA_API UAuraAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UAuraAnimInstanceBase();
	virtual void NativeBeginPlay() override;
	void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	TObjectPtr<AAuraCharacterBase> AnimOwner;
	
	UPROPERTY(BlueprintReadOnly)
	float CharSpeed;

	
};
