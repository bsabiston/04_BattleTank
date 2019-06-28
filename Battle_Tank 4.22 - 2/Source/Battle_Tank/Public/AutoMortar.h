// Copyright Flat Black Films 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutoMortar.generated.h"

UCLASS()
class BATTLE_TANK_API AAutoMortar : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutoMortar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
