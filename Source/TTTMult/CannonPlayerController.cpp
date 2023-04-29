// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void ACannonPlayerController::BeginPlay()
{
	//Call base class
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(CannonMappingContext, 0);
	}

}

void ACannonPlayerController::SetupInputComponent()
{
	//Call base class
	Super::SetupInputComponent();

	//Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent =
		CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(UpwardsMovementAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnUpwardMovementStarted);
		EnhancedInputComponent->BindAction(UpwardsMovementAction, ETriggerEvent::Triggered, this, &ACannonPlayerController::OnUpwardMovementTriggered);

		EnhancedInputComponent->BindAction(DownwardsMovementAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnDownwardMovementStarted);
		EnhancedInputComponent->BindAction(DownwardsMovementAction, ETriggerEvent::Triggered, this, &ACannonPlayerController::OnDownwardMovementTriggered);

		EnhancedInputComponent->BindAction(LeftMovementAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnLeftMovementStarted);
		EnhancedInputComponent->BindAction(LeftMovementAction, ETriggerEvent::Triggered, this, &ACannonPlayerController::OnLeftMovementTriggered);

		EnhancedInputComponent->BindAction(RightMovementAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnRightMovementStarted);
		EnhancedInputComponent->BindAction(RightMovementAction, ETriggerEvent::Triggered, this, &ACannonPlayerController::OnRightMovementTriggered);

		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnShootActionStarted);
	}
}

void ACannonPlayerController::OnUpwardMovementStarted()
{
	HorizontalCurrentStep = HorizontalInitialMovementStep;
}

void ACannonPlayerController::OnUpwardMovementTriggered()
{
	//Tilt cannon right

	//Adjust Launch velocity!!
}

void ACannonPlayerController::OnDownwardMovementStarted()
{
}

void ACannonPlayerController::OnDownwardMovementTriggered()
{
}

void ACannonPlayerController::OnLeftMovementStarted()
{
}

void ACannonPlayerController::OnLeftMovementTriggered()
{
}

void ACannonPlayerController::OnRightMovementStarted()
{
}

void ACannonPlayerController::OnRightMovementTriggered()
{
}

void ACannonPlayerController::OnShootActionStarted()
{
}
