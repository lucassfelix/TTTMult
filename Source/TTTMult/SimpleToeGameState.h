// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	ASimpleToeGameState();

	void SetPlayerControllerTurn(ASimpleToePlayerController& NextPlayer);

	UFUNCTION(BlueprintPure, meta = (WorldContext = "worldContext"))
	static ASimpleToeGameState* GetSimpleToeGameState(UObject* worldContext);

	//Reference to current player
	FORCEINLINE ASimpleToePlayerController* GetCurrentPlayerControllerTurn() {return CurrentPlayerControllerTurn;}

	//Reference to board
	FORCEINLINE TArray<int>* GetBoard() {return &Board;}

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void OnReceivePlayerInput(EPieceType Piece, int BoardPos);


private:
	TArray<int> Board;

	ASimpleToePlayerController* CurrentPlayerControllerTurn;
};
