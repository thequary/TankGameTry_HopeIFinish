// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class GG_TANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable,Category = "Input")
	void SetThrottle(float Throttle);
	
	// max force per track
	UPROPERTY(EditAnywhere, Category = "Setup")
		float TrackMaxDrivingForce = 400000;
};
