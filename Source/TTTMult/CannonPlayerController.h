// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTBoomPlayerState.h"
#include "GameFramework/PlayerController.h"
#include "CannonPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TTTMULT_API ACannonPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	EPlayerTeam InvertIfTeam;
	
	UPROPERTY(EditDefaultsOnly, Category="Cannon Movement")
	float InitialCannonVelocity;

	UPROPERTY(EditDefaultsOnly,  Category = "Cannon Movement")
	float CannonballLaunchVelocityZ;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Movement")
	float HorizontalMaxMovementStep;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Movement")
	float HorizontalMovementStepIncrease;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Movement")
	float HorizontalInitialMovementStep;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Movement")
	float VerticalMaxMovementStep;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Movement")
	float VerticalMovementStepIncrease;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Cannon Movement")
	float VerticalInitialMovementStep;

	UPROPERTY(BlueprintReadOnly)
	FVector CannonballLaunchVelocity;

	/** Mapping Context**/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* CannonMappingContext;

	/** Move Cannon Up Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* UpwardsMovementAction;

	/** Move Cannon Down Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* DownwardsMovementAction;

	/** Move Cannon Left Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LeftMovementAction;

	/** Move Cannon Right Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* RightMovementAction;

	/** Shoot Cannonball Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ShootAction;

protected:

	bool Initialized;
	
	class ATTBoomPlayerState* BoomPlayerState;
	
	class ACannonPawn* CannonPawn;

	UPROPERTY(BlueprintReadWrite)
	float HorizontalCurrentStep;

	UPROPERTY(BlueprintReadWrite)
	float VerticalCurrentStep;
	
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	void LateInitialize();

	//Funcions for input 
	void OnUpwardMovementStarted();
	void OnUpwardMovementTriggered();

	void OnDownwardMovementStarted();
	void OnDownwardMovementTriggered();

	void OnVerticalMovementCanceled();

	void OnLeftMovementStarted();
	void OnLeftMovementTriggered();

	void OnRightMovementStarted();
	void OnRightMovementTriggered();

	void OnHorizontalMovementCanceled();

	void OnShootActionStarted();
};
