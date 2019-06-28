// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"

class ATank;

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;
	FoundAimingComponent(AimingComponent);
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
   
    AimTowardCrosshair();
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetPawn()) return;

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;
    
    FVector HitLocation;
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
    if (bGotHitLocation)
    {
		AimingComponent->AimAt(HitLocation);
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