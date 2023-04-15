// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TTTMultGameState.generated.h"

/**
 * 
 */
UCLASS()
class TTTMULT_API ATTTMultGameState : public AGameState
{
	GENERATED_BODY()

public:
	
	ATTTMultGameState();

	void SetBoardPosition(int piece, int xPosition, int yPosition);

private:

	int board[3][3];
	const int BOARD_SIZE = 3;

	int CheckEndgame();
	
};
