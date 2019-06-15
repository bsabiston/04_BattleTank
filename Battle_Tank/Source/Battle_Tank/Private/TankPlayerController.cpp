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
        return;
    }
    
    FVector HitLocation;
    if (GetSightRayHitLocation(HitLocation))
    {
       UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
    
    FVector LookDirection;
    
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        if (GetLookVectorHitLocation(LookDirection, HitLocation))
        {
            return true;
        }
    }
       

    return false;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{
    FVector WorldLocation;
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
    FHitResult HitResult;
    auto Start = PlayerCameraManager->GetCameraLocation();
    auto End = Start + LookDirection * LineTraceRange;

    if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility))
    {
        HitLocation = HitResult.Location;
        return true;
    }
    else {
        HitLocation = FVector(0);
        return false;
    }
}