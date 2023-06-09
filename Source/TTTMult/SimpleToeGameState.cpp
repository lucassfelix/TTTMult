// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleToeGameState.h"

ASimpleToeGameState::ASimpleToeGameState()
{
}

ASimpleToeGameState* ASimpleToeGameState::GetSimpleToeGameState(UObject* worldContext)
{
	UWorld* world = GEngine->GetWorldFromContextObject(worldContext, EGetWorldErrorMode::ReturnNull);
	return Cast<ASimpleToeGameState>(world->GetGameState());
}


EPieceType ASimpleToeGameState::GetCurrentPlayerPiece()
{
	return CurrentPlayerTurn;
}

void ASimpleToeGameState::SetCurrentPlayerPiece(EPieceType NewPiece)
{
	CurrentPlayerTurn = NewPiece;
}

void ASimpleToeGameState::SortPieces()
{
	auto sortBoardID = [](ABoardPiece &a, ABoardPiece &b) -> bool
	{
		return a.GetBoardPosition() < b.GetBoardPosition();
	};
	
	BoardPieces.Sort(sortBoardID);
		
}

bool ASimpleToeGameState::CheckEndgame()
{

	if(BoardPieces[0]->GetCurrentPiece() == BoardPieces[4]->GetCurrentPiece()
		&& BoardPieces[0]->GetCurrentPiece() == BoardPieces[8]->GetCurrentPiece()
		&& BoardPieces[0]->GetCurrentPiece() != EPieceType::P_Empty)
	{
		//Vitória da peça BoardPieces[0].
		return true;
	}

	if(BoardPieces[2]->GetCurrentPiece() == BoardPieces[4]->GetCurrentPiece()
		&& BoardPieces[2]->GetCurrentPiece() == BoardPieces[6]->GetCurrentPiece()
		&& BoardPieces[2]->GetCurrentPiece() != EPieceType::P_Empty)
	{
		//Vitória da peça BoardPieces[2].
		return true;
	}
	
	for (int i = 0; i < 3; i++)
	{
		int HIndex = i*3;
		if(BoardPieces[HIndex]->GetCurrentPiece() == BoardPieces[HIndex+1]->GetCurrentPiece()
			&& BoardPieces[HIndex]->GetCurrentPiece() == BoardPieces[HIndex+2]->GetCurrentPiece()
			&& BoardPieces[HIndex]->GetCurrentPiece() != EPieceType::P_Empty)
		{
			//Vitória da peça BoardPieces[i].
			return true;
		}

		if(BoardPieces[i]->GetCurrentPiece() == BoardPieces[i+3]->GetCurrentPiece()
			&& BoardPieces[i]->GetCurrentPiece() == BoardPieces[i+6]->GetCurrentPiece()
			&& BoardPieces[i]->GetCurrentPiece() != EPieceType::P_Empty)
		{
			//Vitória da peça BoardPieces[i].
			return true;
		}
	}

	//Checa se ainda há jogo ou se houve empate.
	for (auto BoardPiece : BoardPieces)
	{
		if(BoardPiece->GetCurrentPiece() == EPieceType::P_Empty)
		{
			return false;
		}
	}

	return true;
}


