// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleToePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

//MyIncludes (Unknown if necessary)
#include "BoardPiece.h"
#include "SimpleToePlayerState.h"

ASimpleToePlayerController::ASimpleToePlayerController()
{
	DefaultMouseCursor = EMouseCursor::Default;
}

void ASimpleToePlayerController::BeginPlay()
{
	//Call base class
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext,0);
	}

}

void ASimpleToePlayerController::SetupInputComponent()
{
	//Call base class
	Super::SetupInputComponent();

	//Set up action bindings
	if (UEnhancedInputComponent * EnhancedInputComponent =
		CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(ClickAction,ETriggerEvent::Started,this, &ASimpleToePlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(LogAction, ETriggerEvent::Started, this, &ASimpleToePlayerController::Log);
	}
}

void ASimpleToePlayerController::Log()
{

	ASimpleToePlayerState* SimpleToePlayerState = Cast<ASimpleToePlayerState>(PlayerState);

	if (SimpleToePlayerState->Piece == EPieceType::P_X)
	{
		UE_LOG(LogTemp, Warning, TEXT("Eu possuo a pe�a X"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Eu possuo a pe�a O"));
	}
}

void ASimpleToePlayerController::OnInputStarted()
{
	//Declare variables for cursor Hit
	FHitResult Hit;
	bool bHitSuccessful = false;

	//Get cursor Hit
	bHitSuccessful = GetHitResultUnderCursor(ECC_Visibility, true, Hit);

	//If hit, check if hit Actor is BP_BoardP	iece
	if(bHitSuccessful)
	{
		if (auto* BoardPieceCheck = Cast<ABoardPiece>(Hit.GetActor()))
		{
			auto* ThisPlayerState = Cast<ASimpleToePlayerState>(PlayerState);
			Server_PlacePiece(ThisPlayerState->Piece, BoardPieceCheck->GetBoardPosition());
		}
	}
}

void ASimpleToePlayerController::Server_PlacePiece_Implementation(EPieceType PieceSent , int BoardPos)
{
	Receive_Server_PlacePiece(PieceSent, BoardPos);
}

bool ASimpleToePlayerController::Server_PlacePiece_Validate(EPieceType PieceSent, int BoardPos)
{
	return true;
}


