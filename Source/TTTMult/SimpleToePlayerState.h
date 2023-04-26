// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SimpleToePlayerState.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EPieceType : uint8
{
	P_X	UMETA(DisplayName="X"),
	P_O	UMETA(DisplayName="O")
};
UCLASS()
class TTTMULT_API ASimpleToePlayerState : public APlayerState
{
	GENERATED_BODY()


public:

	ASimpleToePlayerState();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite/*, Replicated*/)
	EPieceType Piece;
	
};
