// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainCharacter/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(AmathIMC);
	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if(SubSystem)
	{
		SubSystem->AddMappingContext(AmathIMC, 0);
	}
	
	CurrentMouseCursor = EMouseCursor::Default;
	bShowMouseCursor = true;

	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue &InputActionValue)
{
	const FVector2D InputValue = InputActionValue.Get<FVector2D>();
	const FRotator PlayerRotation = GetControlRotation();
	const FRotator YawRotation = FRotator(0.f, PlayerRotation.Yaw, 0.f);
	
	const FRotationMatrix RotationMatrix = FRotationMatrix(YawRotation);
	const FVector ForwardDirection = RotationMatrix.GetUnitAxis(EAxis::X);
	const FVector RightDirection = RotationMatrix.GetUnitAxis(EAxis::Y);
	
	// GEngine->AddOnScreenDebugMessage(1, 5.0, FColor::Red, TEXT("YawRotation: ") + YawRotation.ToString());
	// GEngine->AddOnScreenDebugMessage(2, 5.0, FColor::Green, TEXT("ForwardDirection: ") + ForwardDirection.ToString());
	// GEngine->AddOnScreenDebugMessage(3, 5.0, FColor::Blue, TEXT("RightDirection: ") + RightDirection.ToString());
	
	if(APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputValue.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputValue.X);
	}
}

