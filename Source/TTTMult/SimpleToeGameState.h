// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoardPiece.h"
#include "SimpleToePlayerController.h"
#include "GameFramework/GameState.h"
#include "SimpleToeGameState.generated.h"

/**
 * 
 */
UCLASS()
class TTTMULT_API ASimpleToeGameState : public AGameState
{
	GENERATED_BODY()

public:
	//Class Constructor
	ASimpleToeGameState();

	//Array with board piece instances
	UPROPERTY(BlueprintReadWrite)
	TArray<ABoardPiece*> BoardPieces;
	
	//Function to get GameState without cast Requirement
	UFUNCTION(BlueprintPure, meta = (WorldContext = "worldContext"))
	static ASimpleToeGameState* GetSimpleToeGameState(UObject* worldContext);

	//Function to receive player input	
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void OnReceivePlayerInput(EPieceType Piece, int BoardPos);

	
	UFUNCTION(BlueprintPure)
	EPieceType GetCurrentPlayerPiece();

	UFUNCTION(BlueprintCallable)
	void SetCurrentPlayerPiece(EPieceType NewPiece);

	
private:
	
	UFUNCTION(BlueprintCallable)
	void SortPieces();
	
	UFUNCTION(BlueprintCallable)
	bool CheckEndgame();
	
	//UPROPERTY(BlueprintReadOnly)
	EPieceType CurrentPlayerTurn;
	
};
