// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoardPiece.h"
#include "GameFramework/GameState.h"
#include "TTBoomGameState.generated.h"

/**
 * 
 */
UCLASS()
class TTTMULT_API ATTBoomGameState : public AGameState
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	TArray<ABoardPiece*> BoardPieces;

	UFUNCTION(BlueprintPure, meta = (WorldContext = "worldContext"))
	static ATTBoomGameState* GetTTBoomGameState(UObject* worldContext);
	
private:

	UFUNCTION(BlueprintCallable)
	void SortPieces();
	
	UFUNCTION(BlueprintCallable)
	bool CheckEndgame();
	
};
