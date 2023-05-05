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
	
	FPredictProjectilePathParams Params;
	
	Params.StartLocation = RootComponent->GetComponentLocation();
	//Params.LaunchVelocity = FVector3d(CannonballLaunchVelocityX,CannonballLaunchVelocityY,CannonballLaunchVelocityZ);
    	Params.LaunchVelocity = CannonballLaunchVelocity;
	Params.bTraceWithCollision = true;
	Params.DrawDebugType = EDrawDebugTrace::ForOneFrame;
	Params.MaxSimTime = 10;
	Params.ProjectileRadius = ProjectileRadius;
	
	
 	Server_SendDrawAim(Params);
}

// Called to bind functionality to input
void ACannonPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACannonPawn::SetupInitialVelocity(FVector InitialPath)
{
	CannonballLaunchVelocity = InitialPath;
}

void ACannonPawn::Server_SendDrawAim_Implementation(FPredictProjectilePathParams Params)
{
	Multiacst_DrawAim(Params);
}

bool ACannonPawn::Server_SendDrawAim_Validate(FPredictProjectilePathParams Params)
{
	return true;
}

void ACannonPawn::Multiacst_DrawAim(FPredictProjectilePathParams Params)
{
	FPredictProjectilePathResult Results;
	
	UGameplayStatics::PredictProjectilePath(GetWorld(), Params,Results);
}






