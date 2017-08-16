// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class GG_TANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 8; 

	UPROPERTY(EditAnywhere)
		float MaxElevationDegrees = 25;

	UPROPERTY(EditAnywhere)
		float MinElevationDegrees = -10;

};
