// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/EffectActorTest.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "Components/SphereComponent.h"


// Sets default values
AEffectActorTest::AEffectActorTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	SetRootComponent(Sphere);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEffectActorTest::OnOverLapActor);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AEffectActorTest::OnEndOverlap);
}

void AEffectActorTest::OnOverLapActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ApplyEffectToTarget(OtherActor, GameplayEffectClassInput);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Overlap Test");
}

void AEffectActorTest::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	RemoveEffectOffTarget(OtherActor, GameplayEffectClassInput);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "Overlap End");
}

void AEffectActorTest::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	UGameplayEffect* EffectInstance = NewObject<UGameplayEffect>(GetTransientPackage(), GameplayEffectClass);
	TargetASC->ApplyGameplayEffectToSelf(EffectInstance, 1, EffectContextHandle);
}

void AEffectActorTest::RemoveEffectOffTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;
	
	TargetASC->RemoveActiveGameplayEffectBySourceEffect(GameplayEffectClass, TargetASC);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "EndOverlap");
}

