// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TTBoomPlayerState.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EPlayerTeam : uint8
{
	P_X	UMETA(DisplayName = "Team_X"),
	P_O	UMETA(DisplayName = "Team_O"),
	P_Empty UMETA(DisplayName = "Empty")
};

UCLASS()
class TTTMULT_API ATTBoomPlayerState : public APlayerState
{
	GENERATED_BODY()
	

public:

	//Stores player team information.
	UPROPERTY(BlueprintReadWrite)
	EPlayerTeam PlayerTeam;

	//Is this player the team leader?
	UPROPERTY(BlueprintReadWrite)
	bool IsTeamLeader;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float CannonCooldown;

};
