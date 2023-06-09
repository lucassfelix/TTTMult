// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

#include "CannonPawn.h"
#include "TTBoomPlayerState.h"
#include "Net/UnrealNetwork.h"


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

	InvertIfTeam = EPlayerTeam::P_O;

	Initialized = false;

	
}

bool ACannonPlayerController::LateInitialize()
{
	if (Initialized) return true;

	if (CannonPawn == nullptr)
	{
		CannonPawn = Cast<ACannonPawn>(GetPawn());
	}

	if (BoomPlayerState == nullptr)
	{
		BoomPlayerState = GetPlayerState<ATTBoomPlayerState>();
	}

	if(BoomPlayerState != nullptr && CannonPawn != nullptr)
	{
		CannonballLaunchVelocity =
			BoomPlayerState->PlayerTeam == InvertIfTeam
			? FVector(-InitialCannonVelocity,0,HeightStartVelocity)
			: FVector(InitialCannonVelocity,0, HeightStartVelocity);
		
		CannonPawn->DrawPath(CannonballLaunchVelocity);
		Initialized = true;
	}

	return Initialized;
}

void ACannonPlayerController::Tick(float DeltaTime)
{
	if (!LateInitialize()) return;
	
	if (BoomPlayerState->PlayerTeam == InvertIfTeam )
	{
		CannonballLaunchVelocity += FVector(-VerticalCurrentStep, -HorizontalCurrentStep,HeightCurrentStep) * DeltaTime;
	}
	else
	{
		CannonballLaunchVelocity += FVector(VerticalCurrentStep, HorizontalCurrentStep, HeightCurrentStep) * DeltaTime;
	}
	
	if (IsLocalPlayerController())
	{
		CannonPawn->DrawPath(CannonballLaunchVelocity);
	}

	if (HasAuthority())
	{
		TimeBetweenLastShot_Server += DeltaTime;
	}

	TimeBetweenLastShot_Client += DeltaTime;
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
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &ACannonPlayerController::OnShootActionTriggered);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Completed, this, &ACannonPlayerController::OnShootActionCanceled);

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

void ACannonPlayerController::OnShootActionTriggered()
{
	HeightCurrentStep += HeightStepIncrease;
	
	if (HeightCurrentStep > HeightMaxStep)
	{
		HeightCurrentStep = HeightMaxStep;
	}

}

void ACannonPlayerController::OnShootActionCanceled()
{
	EPlayerTeam Team = BoomPlayerState->PlayerTeam;
	OnSpawnCannonball(CannonballLaunchVelocity, Team, CannonPawn->GetRootComponent()->GetComponentTransform());
	CannonballLaunchVelocity = FVector(CannonballLaunchVelocity.X, CannonballLaunchVelocity.Y, HeightStartVelocity);
	HeightCurrentStep = 0;
}

void ACannonPlayerController::OnHorizontalMovementCanceled()
{
	HorizontalCurrentStep = 0;
}

void ACannonPlayerController::OnVerticalMovementCanceled()
{
	VerticalCurrentStep = 0;
}
