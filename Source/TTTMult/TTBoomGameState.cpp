// Fill out your copyright notice in the Description page of Project Settings.


#include "TTBoomGameState.h"



ATTBoomGameState* ATTBoomGameState::GetTTBoomGameState(UObject* worldContext)
{
	UWorld* world = GEngine->GetWorldFromContextObject(worldContext, EGetWorldErrorMode::ReturnNull);
	return Cast<ATTBoomGameState>(world->GetGameState());
}


void ATTBoomGameState::SortPieces()
{
	auto sortBoardID = [](ABoardPiece &a, ABoardPiece &b) -> bool
	{
		return a.GetBoardPosition() < b.GetBoardPosition();
	};
	
	BoardPieces.Sort(sortBoardID);
		
}

//-1 = Not finished
//0 = DRAW
//1 = X_Wins
//2 = O_Wins
int ATTBoomGameState::CheckEndgame()
{

	if(BoardPieces[0]->GetCurrentPiece() == BoardPieces[4]->GetCurrentPiece()
		&& BoardPieces[0]->GetCurrentPiece() == BoardPieces[8]->GetCurrentPiece()
		&& BoardPieces[0]->GetCurrentPiece() != EPieceType::P_Empty)
	{
		//Vitória da peça BoardPieces[0].
		return BoardPieces[0]->GetCurrentPiece() == EPieceType::P_X ? 1 : 2;
	}

	if(BoardPieces[2]->GetCurrentPiece() == BoardPieces[4]->GetCurrentPiece()
		&& BoardPieces[2]->GetCurrentPiece() == BoardPieces[6]->GetCurrentPiece()
		&& BoardPieces[2]->GetCurrentPiece() != EPieceType::P_Empty)
	{
		//Vitória da peça BoardPieces[2].
		return BoardPieces[2]->GetCurrentPiece() == EPieceType::P_X ? 1 : 2;
	}
	
	for (int i = 0; i < 3; i++)
	{
		int HIndex = i*3;
		if(BoardPieces[HIndex]->GetCurrentPiece() == BoardPieces[HIndex+1]->GetCurrentPiece()
			&& BoardPieces[HIndex]->GetCurrentPiece() == BoardPieces[HIndex+2]->GetCurrentPiece()
			&& BoardPieces[HIndex]->GetCurrentPiece() != EPieceType::P_Empty)
		{
			//Vitória da peça BoardPieces[HIndex].
			return BoardPieces[HIndex]->GetCurrentPiece() == EPieceType::P_X ? 1 : 2;
		}

		if(BoardPieces[i]->GetCurrentPiece() == BoardPieces[i+3]->GetCurrentPiece()
			&& BoardPieces[i]->GetCurrentPiece() == BoardPieces[i+6]->GetCurrentPiece()
			&& BoardPieces[i]->GetCurrentPiece() != EPieceType::P_Empty)
		{
			//Vitória da peça BoardPieces[i].
			return BoardPieces[i]->GetCurrentPiece() == EPieceType::P_X ? 1 : 2;
		}
	}

	//Checa se ainda há jogo ou se houve empate.
	for (auto BoardPiece : BoardPieces)
	{
		if(BoardPiece->GetCurrentPiece() == EPieceType::P_Empty)
		{
			return -1;
		}
	}
	return 0;
}

void ATTBoomGameState::ResetGamePieces()
{
	for (auto BoardPiece : BoardPieces			)
	{
		BoardPiece->ResetPiece();
	}
}
