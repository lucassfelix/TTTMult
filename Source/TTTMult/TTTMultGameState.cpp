// Fill out your copyright notice in the Description page of Project Settings.


#include "TTTMultGameState.h"


ATTTMultGameState::ATTTMultGameState()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = 0;
		}
	}
}

void ATTTMultGameState::SetBoardPosition(int piece, int xPosition, int yPosition)
{
	board[xPosition][yPosition] = piece;
}

int ATTTMultGameState::CheckEndgame()
{

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{

		}
	}


	return false;
}
