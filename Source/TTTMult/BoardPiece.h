// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleToePlayerState.h"
#include "GameFramework/Actor.h"
#include "BoardPiece.generated.h"

UCLASS()
class TTTMULT_API ABoardPiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoardPiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	int GetBoardPosition();
	
	UFUNCTION(BlueprintPure)
	EPieceType GetCurrentPiece();

	UFUNCTION(BlueprintCallable)
	void SetCurrentPiece(const EPieceType Piece);

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void OnChangeMaterial(UMaterialInterface* Material);

private:

	UPROPERTY(EditAnywhere,Category="TicTacToe")
	int BoardPosition;

	EPieceType CurrentPiece;
	
};
