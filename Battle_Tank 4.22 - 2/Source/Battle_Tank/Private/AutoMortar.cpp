// Copyright Flat Black Films 2019


#include "AutoMortar.h"

// Sets default values
AAutoMortar::AAutoMortar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAutoMortar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAutoMortar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

