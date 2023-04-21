// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleToePawn.h"

// Sets default values
ASimpleToePawn::ASimpleToePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimpleToePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleToePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASimpleToePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

