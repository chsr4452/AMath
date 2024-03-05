// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainCharacter/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
AAuraPlayerController::AAuraPlayerController()
{

}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	checkf(AmathIMC == nullptr, TEXT("Set Input Mapping Context in Controller!"));
	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	SubSystem->AddMappingContext(AmathIMC, 0);

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

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputValue.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputValue.X);
	}
}

