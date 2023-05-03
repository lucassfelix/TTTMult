// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

#include "CannonPawn.h"

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


	Initialized = false;

}

void ACannonPlayerController::LateInitialize()
{
	CannonPawn = Cast<ACannonPawn>(GetPawn());
	if (CannonPawn != nullptr)
	{
		Initialized = true;
	}
}

void ACannonPlayerController::Tick(float DeltaTime)
{
	if (!Initialized)
	{
		LateInitialize();
		return;
	}

	CannonPawn->CannonballLaunchVelocity += FVector(VerticalCurrentStep, HorizontalCurrentStep,0);

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
		EnhancedInputComponent->BindAction(UpwardsMovementAction, ETriggerEvent::Completed, this, &ACannonPlayerController::OnVerticalMovementCanceled);


		EnhancedInputComponent->BindAction(DownwardsMovementAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnDownwardMovementStarted);
		EnhancedInputComponent->BindAction(DownwardsMovementAction, ETriggerEvent::Triggered, this, &ACannonPlayerController::OnDownwardMovementTriggered);
		EnhancedInputComponent->BindAction(DownwardsMovementAction, ETriggerEvent::Completed, this, &ACannonPlayerController::OnVerticalMovementCanceled);


		EnhancedInputComponent->BindAction(LeftMovementAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnLeftMovementStarted);
		EnhancedInputComponent->BindAction(LeftMovementAction, ETriggerEvent::Triggered, this, &ACannonPlayerController::OnLeftMovementTriggered);
		EnhancedInputComponent->BindAction(LeftMovementAction, ETriggerEvent::Completed, this, &ACannonPlayerController::OnHorizontalMovementCanceled);


		EnhancedInputComponent->BindAction(RightMovementAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnRightMovementStarted);
		EnhancedInputComponent->BindAction(RightMovementAction, ETriggerEvent::Triggered, this, &ACannonPlayerController::OnRightMovementTriggered);
		EnhancedInputComponent->BindAction(RightMovementAction, ETriggerEvent::Completed, this, &ACannonPlayerController::OnHorizontalMovementCanceled);


		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &ACannonPlayerController::OnShootActionStarted);
	}
}

void ACannonPlayerController::OnUpwardMovementStarted()
{
	VerticalCurrentStep = VerticalInitialMovementStep;
}

void ACannonPlayerController::OnUpwardMovementTriggered()
{
	if (VerticalCurrentStep <= VerticalMaxMovementStep)
	{
		VerticalCurrentStep += VerticalMovementStepIncrease;
	}

	if (VerticalCurrentStep > VerticalMaxMovementStep)
	{
		VerticalCurrentStep = VerticalMaxMovementStep;
	}
}

void ACannonPlayerController::OnDownwardMovementStarted()
{
	VerticalCurrentStep = -VerticalInitialMovementStep;
}

void ACannonPlayerController::OnDownwardMovementTriggered()
{
	if (FGenericPlatformMath::Abs(VerticalCurrentStep) <= VerticalMaxMovementStep)
	{
		VerticalCurrentStep -= VerticalMovementStepIncrease;
	}

	if (FGenericPlatformMath::Abs(VerticalCurrentStep) > VerticalMaxMovementStep)
	{
		VerticalCurrentStep = -VerticalMaxMovementStep;
	}
}


void ACannonPlayerController::OnLeftMovementStarted()
{
	HorizontalCurrentStep = -HorizontalInitialMovementStep;
}

void ACannonPlayerController::OnLeftMovementTriggered()
{
	if (FGenericPlatformMath::Abs(HorizontalCurrentStep) <= HorizontalMaxMovementStep)
	{
		HorizontalCurrentStep -= HorizontalMovementStepIncrease;
	}

	if (FGenericPlatformMath::Abs(HorizontalCurrentStep) > HorizontalMaxMovementStep)
	{
		HorizontalCurrentStep = -HorizontalMaxMovementStep;
	}
}


void ACannonPlayerController::OnRightMovementStarted()
{
	HorizontalCurrentStep = HorizontalInitialMovementStep;
}

void ACannonPlayerController::OnRightMovementTriggered()
{
	if (FGenericPlatformMath::Abs(HorizontalCurrentStep) <= HorizontalMaxMovementStep)
	{
		HorizontalCurrentStep += HorizontalMovementStepIncrease;
	}

	if (FGenericPlatformMath::Abs(HorizontalCurrentStep) > HorizontalMaxMovementStep)
	{
		HorizontalCurrentStep = HorizontalMaxMovementStep;
	}
}

void ACannonPlayerController::OnShootActionStarted()
{
}

void ACannonPlayerController::OnHorizontalMovementCanceled()
{
	HorizontalCurrentStep = 0;
}

void ACannonPlayerController::OnVerticalMovementCanceled()
{
	VerticalCurrentStep = 0;
}
