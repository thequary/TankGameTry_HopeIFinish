// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerControler.generated.h"

/**
 * 
 */
UCLASS()
class GG_TANKS_API ATankPlayerControler : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;



private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector&)const;


	
	// Var
	UPROPERTY(EditAnywhere)
	float  CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float  CrossHairYLocation = 0.3333;
};
