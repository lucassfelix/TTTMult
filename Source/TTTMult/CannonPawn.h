// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "CannonPawn.generated.h"

UCLASS()
class TTTMULT_API ACannonPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACannonPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool ShouldDrawAim = false;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ProjectileRadius;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxSimTime;
	
	void DrawPath(FVector LaunchVelocity);
};
