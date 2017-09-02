// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * TankTrack este utilizat ca sa facem ceva cu trank'ul sau.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class GG_TANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20;
	
};
