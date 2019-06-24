// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	private:
	
	void BeginPlay() override;
	void Tick(float DeltaTime);
	ATank *GetControlledTank() const;
	ATank *GetPlayerTank() const;
};