// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardPiece.h"

// Sets default values
ABoardPiece::ABoardPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoardPiece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoardPiece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ABoardPiece::GetBoardPosition()
{
	return BoardPosition;
}

EPieceType ABoardPiece::GetCurrentPiece()
{
	return CurrentPiece;
}

void ABoardPiece::ResetPiece()
{
	CurrentPiece = EPieceType::P_Empty;
	OnChangeMaterial(EmptyMaterial);
}

void ABoardPiece::SetCurrentPiece(const EPieceType Piece)
{
	CurrentPiece = Piece;
}
