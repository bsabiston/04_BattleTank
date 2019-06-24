// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;

// Hold barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	

public:	
	UTankAimingComponent();
	void SetBarrelReference(UTankBarrel *BarrelToSet);
	void SetTurretReference(UTankTurret *TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
