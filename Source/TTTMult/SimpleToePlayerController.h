// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "SimpleToePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TTTMULT_API ASimpleToePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASimpleToePlayerController();

	/** Mapping Context**/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;
	
	/** Click Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* ClickAction;

protected:

	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;

	void OnInputStarted();
	
};
