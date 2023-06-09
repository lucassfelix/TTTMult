// Fill out your copyright notice in the Description page of Project Settings.


#include "TTBoomGameMode.h"

#include "CannonPlayerController.h"
#include "EngineUtils.h"
#include "TTBoomPlayerState.h"
#include "GameFramework/PlayerStart.h"

bool ATTBoomGameMode::ReadyToStartMatch_Implementation()
{
	Super::ReadyToStartMatch_Implementation();
	return NumPlayers == 2;
}

AActor* ATTBoomGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	UE_LOG(LogTemp,Warning,TEXT("ChoosePlayerStart"))
	

	auto* CannonPlayer = Cast<ACannonPlayerController>(Player);

	if (CannonPlayer==nullptr)
	{
		//MAYBE SHIP PLAYER!!
	}
	
	auto* PlayerState =CannonPlayer->GetPlayerState<ATTBoomPlayerState>();

	UE_LOG(LogTemp,Warning,TEXT("Num players = %d"),NumPlayers);
	PlayerState->PlayerTeam = NumPlayers == 1 ? EPlayerTeam::P_X : EPlayerTeam::P_O;

	FName ExpectedStart = PlayerState->PlayerTeam == EPlayerTeam::P_X ? "X" : "O";

	if (PlayerState->PlayerTeam == EPlayerTeam::P_X)
	{
		PlayerState->IsTeamLeader = true;
	}
	else
	{
	}

	
	UWorld* World = GetWorld();
	for (TActorIterator<APlayerStart> It(World); It; ++It)
	{
		auto* PlayerStart = *It;

		if(PlayerStart->PlayerStartTag.IsEqual(ExpectedStart))
		{
			return  PlayerStart;
		}
	}
	return Super::ChoosePlayerStart_Implementation(Player);
}

void ATTBoomGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	
	PlayerControllerList.Add(NewPlayer);
}
