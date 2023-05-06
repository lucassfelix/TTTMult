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

	/**
	///
	///  Cannon Shot Variables
	///
	**/

	UPROPERTY(BlueprintReadWrite)
	float TimeBetweenLastShot_Server;

	UPROPERTY(BlueprintReadWrite)
	float TimeBetweenLastShot_Client;

	UPROPERTY(EditAnywhere, Category = "Cannon Shot")
	float CooldownBetweenShots;

	/**
	///
	///  Cannon Movement Variables
	///
	**/
	
	/** Direction the cannon will be pointing at Game Start **/
	UPROPERTY(EditDefaultsOnly, Category="Cannon Movement")
	float InitialCannonVelocity;

	/** The height (Z) of the Cannonball arch **/
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

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_CannonballLaunchVelocity)
	FVector CannonballLaunchVelocity;

	/**
	///
	///  Input Mapping Variables
	///
	**/

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

	/**
	///
	/// Events
	///
	**/

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ReceiveOnBallHit(EPlayerTeam ShotBy, AActor* Other);

	UFUNCTION()
	void OnRep_CannonballLaunchVelocity();


protected:

        UPROPERTY(BlueprintReadWrite)
	float HorizontalCurrentStep;

	UPROPERTY(BlueprintReadWrite)
	float VerticalCurrentStep;
	
	class ATTBoomPlayerState* BoomPlayerState;
	
	class ACannonPawn* CannonPawn;

	bool Initialized;
	
	bool LateInitialize();
	
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	/**
	///
	/// Input handlers
	///
	**/
	
	void OnUpwardMovementStarted();
	void OnUpwardMovementTriggered();

	void OnDownwardMovementStarted();
	void OnDownwardMovementTriggered();

	void OnLeftMovementStarted();
	void OnLeftMovementTriggered();

	void OnRightMovementStarted();
	void OnRightMovementTriggered();
	
	void OnVerticalMovementCanceled();
	void OnHorizontalMovementCanceled();

	void OnShootActionStarted();
};
