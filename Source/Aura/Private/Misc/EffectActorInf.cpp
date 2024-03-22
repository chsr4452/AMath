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
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	SetRootComponent(Sphere);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEffectActorInf::OnOverLapActor);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AEffectActorInf::OnEndOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AEffectActorInf::Test);
}

void AEffectActorInf::OnOverLapActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ApplyEffectToTarget(OtherActor);
}

void AEffectActorInf::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	RemoveEffectOffTarget(OtherActor);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "EndOverlap");
}

void AEffectActorInf::ApplyEffectToTarget(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;
	if(GameplayEffectClassInput)
	{
		EffectInstance = NewObject<UGameplayEffect>(GetTransientPackage(), GameplayEffectClassInput);
	}
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	
	TargetASC->ApplyGameplayEffectToSelf(EffectInstance, 1, EffectContextHandle);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Overlap");
	
}

void AEffectActorInf::RemoveEffectOffTarget(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;
	
	TargetASC->RemoveActiveGameplayEffectBySourceEffect(GameplayEffectClassInput, TargetASC);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "EndOverlap");
}

void AEffectActorInf::Test(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "EndOverlap");
}



