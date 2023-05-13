// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BoardPiece.h"
#include "GameFramework/GameState.h"
#include "TTBoomPlayerState.h"
#include "TTBoomGameState.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EPlayMode : uint8
{
	TurnBased	UMETA(DisplayName = "Turn Baed"),
	FreeMode	UMETA(DisplayName = "Free Mode")
};


UCLASS()
class TTTMULT_API ATTBoomGameState : public AGameState
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	TArray<ABoardPiece*> BoardPieces;

	UFUNCTION(BlueprintPure, meta = (WorldContext = "worldContext"))
	static ATTBoomGameState* GetTTBoomGameState(UObject* worldContext);
	
	UFUNCTION(BlueprintPure)
	EPlayMode GetPlayMode();
	
	UFUNCTION(BlueprintPure)
	EPlayerTeam GetCurrentPlayer();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	EPlayMode PlayMode;

	UPROPERTY(BlueprintReadWrite)
	EPlayerTeam CurrentPlayerTurn;

	UFUNCTION(BlueprintCallable)
	void SetCurrentPlayerTurn(EPlayerTeam Player);

	UFUNCTION(BlueprintCallable)
	void SetPlayMode(EPlayMode NewPlayMode);

private:

	UFUNCTION(BlueprintCallable)
	void SortPieces();
	
	UFUNCTION(BlueprintCallable)
	int CheckEndgame();

	UFUNCTION(BlueprintCallable)
	void ResetGamePieces();
	
};
