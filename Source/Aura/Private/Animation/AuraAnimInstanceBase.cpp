// Fill out your copyright notice in the Description page of Project Settings.


#include "Aura/Public/Animation/AuraAnimInstanceBase.h"

#include "SceneRenderTargetParameters.h"
#include "Aura/Public/Characters/AuraCharacterBase.h"

UAuraAnimInstanceBase::UAuraAnimInstanceBase()
{
	
}

void UAuraAnimInstanceBase::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	AnimOwner = Cast<AAuraCharacterBase>(GetOwningActor());
}

void UAuraAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(AnimOwner)
	{
		CharSpeed = AnimOwner->GetVelocity().Size2D();
		// GEngine->AddOnScreenDebugMessage(1, 5.0, FColor::Red, FString::Printf(TEXT("%f"), CharSpeed));
	}
}
