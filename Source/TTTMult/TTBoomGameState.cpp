// Fill out your copyright notice in the Description page of Project Settings.


#include "TTBoomGameState.h"



ATTBoomGameState* ATTBoomGameState::GetTTBoomGameState(UObject* worldContext)
{
	UWorld* world = GEngine->GetWorldFromContextObject(worldContext, EGetWorldErrorMode::ReturnNull);
	return Cast<ATTBoomGameState>(world->GetGameState());
}