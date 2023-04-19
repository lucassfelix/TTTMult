// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TTTMultPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TTTMULT_API ATTTMultPlayerState : public APlayerState
{
	GENERATED_BODY()

private:

	int PlayerPiece;

public:

	UFUNCTION(BlueprintCallable)
	void SetPlayerPiece(int piece);

	UFUNCTION(BlueprintPure)
	int GetPlayerPiece();

};
