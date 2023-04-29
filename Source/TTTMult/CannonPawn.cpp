// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonPawn.h"

// Sets default values
ACannonPawn::ACannonPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACannonPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACannonPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACannonPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

