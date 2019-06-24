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

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (GetPlayerTank())
    {
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
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

