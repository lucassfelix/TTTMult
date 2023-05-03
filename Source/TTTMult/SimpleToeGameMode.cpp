// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleToeGameMode.h"

#include "SimpleToePlayerController.h"
#include "SimpleToePlayerState.h"


void ASimpleToeGameMode::PostLogin(APlayerController* NewPlayer) {
	Super::PostLogin(NewPlayer);


	auto* NewSimpleToePlayerController = Cast<ASimpleToePlayerController>(NewPlayer);

	auto* NewSimpleToePlayerState = Cast<ASimpleToePlayerState>(NewSimpleToePlayerController->PlayerState);

	if (NumPlayers == 0)
	{
		NewSimpleToePlayerState->Piece = EPieceType::P_X;
	}
	else
	{
		NewSimpleToePlayerState->Piece = EPieceType::P_O;
	}

}
