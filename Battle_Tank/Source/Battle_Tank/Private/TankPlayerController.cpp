// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

ATank *ATankPlayerController::GetControlledTank() const
{
    ATank *Tank = Cast<ATank>(GetPawn());
    return Tank;
}


// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

   
    AimTowardCrosshair();
}

void ATankPlayerController::AimTowardCrosshair()
{
    ATank *Tank = GetControlledTank();
    if (!Tank)
    {
        UE_LOG(LogTemp, Error, TEXT("Did not find Tank!"));
    }
}