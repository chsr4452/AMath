// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectActorTest.generated.h"

class UGameplayEffect;
class USphereComponent;

UCLASS()
class AURA_API AEffectActorTest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEffectActorTest();
	UPROPERTY(EditAnywhere, Category="User Property")
	TObjectPtr<USphereComponent> Sphere;
	
	UPROPERTY(EditAnywhere, Category="User Property")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, Category = "Effect Class")
	TSubclassOf<UGameplayEffect> GameplayEffectClassInput;

	UFUNCTION()
	virtual void OnOverLapActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UFUNCTION(BlueprintCallable)
	void RemoveEffectOffTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
};
