// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TTBoomGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TTTMULT_API ATTBoomGameMode : public AGameMode
{
	GENERATED_BODY()


public:

	TArray<APlayerController*> PlayerControllerList;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool ReadyToStart;
	
	virtual bool ReadyToStartMatch_Implementation() override;
	
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;
	
	virtual void PostLogin(APlayerController* NewPlayer) override;

	
};
