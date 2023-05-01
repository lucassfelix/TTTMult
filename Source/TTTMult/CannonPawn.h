// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double CannonballLaunchVelocityX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double CannonballLaunchVelocityY;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double CannonballLaunchVelocityZ;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ProjectileRadius;
};
