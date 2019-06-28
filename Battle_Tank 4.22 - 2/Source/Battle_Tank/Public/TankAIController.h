// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		// How close can the AI Tank get to the player
		float AcceptanceRadius = 8000;
public:

	private:
	
	void BeginPlay() override;
	void Tick(float DeltaTime);

	
};
