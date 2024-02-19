﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Aura/Public/Characters/AuraCharacterBase.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class AURA_API AEnemyCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
	