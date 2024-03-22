// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectActorInf.generated.h"

class USphereComponent;
class UGameplayEffect;

UCLASS()
class AURA_API AEffectActorInf : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEffectActorInf();

protected:
	// Called when the game starts or when spawned
	
	UPROPERTY(EditAnywhere, Category="User Property")
	TObjectPtr<USphereComponent> Sphere;
	
	UPROPERTY(EditAnywhere, Category="User Property")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, Category = "Effect Class")
	TSubclassOf<UGameplayEffect> GameplayEffectClassInput;


	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Effect Class")
	AActor* TestActor;

	TObjectPtr<UGameplayEffect> EffectInstance;
	
	UFUNCTION()
	virtual void OnOverLapActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor);
	
	UFUNCTION(BlueprintCallable)
	void RemoveEffectOffTarget(AActor* TargetActor);
	
	UFUNCTION(BlueprintCallable)
	virtual void Test(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	

	
};
