// Fill out your copyright notice in the Description page of Project Settings.


#include "CannonPawn.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStaticsTypes.h"

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

void ACannonPawn::DrawPath(FVector LaunchVelocity)
{
	FPredictProjectilePathParams Params;

	Params.StartLocation = GetActorLocation();
	//Params.LaunchVelocity = FVector3d(CannonballLaunchVelocityX,CannonballLaunchVelocityY,CannonballLaunchVelocityZ);
	Params.LaunchVelocity = LaunchVelocity;
	Params.bTraceWithCollision = true;
	Params.DrawDebugType = EDrawDebugTrace::ForOneFrame;
	Params.MaxSimTime = MaxSimTime;
	Params.ProjectileRadius = ProjectileRadius;
	
	FPredictProjectilePathResult Results;

	UGameplayStatics::PredictProjectilePath(GetWorld(), Params, Results);
	
}

// Called to bind functionality to input
void ACannonPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}









