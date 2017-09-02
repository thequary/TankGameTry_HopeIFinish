// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Foward declaration
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class GG_TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = "Fiering")
		void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprints;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 50000; // TODO find sensible default

	UPROPERTY(EditAnywhere, Category = "Setup")
	float ReloadTimeInSecond = 3;

	UTankBarrel* Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;
};
