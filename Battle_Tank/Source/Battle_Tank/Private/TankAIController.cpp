// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

    ATank *Tank = GetControlledTank();
    if (Tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Got AI Tank %s"), *(Tank->GetName()));
    }

    ATank *PlayerTank = GetPlayerTank();
    if (PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Got Player Tank %s"), *(PlayerTank->GetName()));
    }
}

ATank *ATankAIController::GetControlledTank() const
{
    ATank *Tank = Cast<ATank>(GetPawn());
    return Tank;
}


ATank *ATankAIController::GetPlayerTank() const
{
    ATank *Tank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    return Tank;
}