// Fill out your copyright notice in the Description page of Project Settings.


#include "Misc/EffectActor.h"
#include "GameplayAbilitySystem/AuraAttributeSet.h"
#include "Characters/MainCharacter/MainCharacter.h"
#include "Components/SphereComponent.h"


// Sets default values
AEffectActor::AEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	SetRootComponent(Sphere);
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AEffectActor::OnOverLapActor);
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEffectActor::OnOverLapActor(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Red, "Overlapped");
	
	AMainCharacter* MainChar = Cast<AMainCharacter>(OtherActor);
	UAuraAttributeSet* Attribute = MainChar->GetAttributeSet();
	Attribute->SetHealth(Attribute->GetHealth() + 50.f);
}
