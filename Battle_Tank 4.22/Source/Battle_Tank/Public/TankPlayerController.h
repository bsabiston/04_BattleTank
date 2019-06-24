// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	private:
	ATank *GetControlledTank() const;
	UPROPERTY (EditAnywhere) 
	float CrossHairXLocation = 0.5;

	UPROPERTY (EditAnywhere) 
	float CrossHairYLocation = 0.33335;

	UPROPERTY (EditAnywhere) 
	float LineTraceRange = 1000000;

	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void AimTowardCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
};
