// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/EffectActorInf.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffect.h"
#include "Components/SphereComponent.h"
#include "Misc/EffectActor.h"
#include "AbilitySystemComponent.h"


// Sets default values
AEffectActorInf::AEffectActorInf()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	SetRootComponent(Sphere);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEffectActorInf::OnOverLapActor);
}

void AEffectActorInf::OnOverLapActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ApplyEffectToTarget(OtherActor, GameplayEffectClassInput);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Overlap");
}

void AEffectActorInf::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	UGameplayEffect* EffectInstance = NewObject<UGameplayEffect>(GetTransientPackage(), GameplayEffectClass);
	TargetASC->ApplyGameplayEffectToSelf(EffectInstance, 1, EffectContextHandle);
	
}



