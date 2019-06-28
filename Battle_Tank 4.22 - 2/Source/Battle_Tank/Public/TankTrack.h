// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 *  TankTrack is used to set maximum driving force, and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	/* Booo dee boop */
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000;  // assume 40 tonne tank and 1g acceleration

private:
	UTankTrack();
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit);

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
