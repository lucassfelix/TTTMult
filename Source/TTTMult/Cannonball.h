// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTBoomPlayerState.h"
#include "GameFramework/Actor.h"
#include "Cannonball.generated.h"

UCLASS()
class TTTMULT_API ACannonball : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACannonball();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite)
	EPlayerTeam ShotBy;
	
	UFUNCTION(BlueprintImplementableEvent)
	void Launch(FVector LaunchVelocity);
	
};
