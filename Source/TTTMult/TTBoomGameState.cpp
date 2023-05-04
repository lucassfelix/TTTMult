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

bool ATTBoomGameState::CheckEndgame()
{

	if(BoardPieces[0]->GetCurrentPiece() == BoardPieces[4]->GetCurrentPiece()
		&& BoardPieces[0]->GetCurrentPiece() == BoardPieces[8]->GetCurrentPiece()
		&& BoardPieces[0]->GetCurrentPiece() != EPieceType::P_Empty)
	{
		UE_LOG(LogTemp, Warning, TEXT("Exited on Loop 0"));
		//Vitória da peça BoardPieces[0].
		return true;
	}

	if(BoardPieces[2]->GetCurrentPiece() == BoardPieces[4]->GetCurrentPiece()
		&& BoardPieces[2]->GetCurrentPiece() == BoardPieces[6]->GetCurrentPiece()
		&& BoardPieces[2]->GetCurrentPiece() != EPieceType::P_Empty)
	{
		//Vitória da peça BoardPieces[2].
		UE_LOG(LogTemp, Warning, TEXT("Exited on Loop 1"));
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
			UE_LOG(LogTemp, Warning, TEXT("Exited on Loop 2"));
			return true;
		}

		if(BoardPieces[i]->GetCurrentPiece() == BoardPieces[i+3]->GetCurrentPiece()
			&& BoardPieces[i]->GetCurrentPiece() == BoardPieces[i+6]->GetCurrentPiece()
			&& BoardPieces[i]->GetCurrentPiece() != EPieceType::P_Empty)
		{
			//Vitória da peça BoardPieces[i].
			UE_LOG(LogTemp, Warning, TEXT("Exited on Loop 3"));
			return true;
		}
	}

	//Checa se ainda há jogo ou se houve empate.
	for (auto BoardPiece : BoardPieces)
	{
		if(BoardPiece->GetCurrentPiece() == EPieceType::P_Empty)
		{
			UE_LOG(LogTemp, Warning, TEXT("Exited on Loop 4"));
			return false;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Exited at func end"));
	return true;
}