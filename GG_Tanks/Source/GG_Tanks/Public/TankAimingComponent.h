// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
	enum class EFiringStatus : uint8
	{
		Reloading,
		Aiming,
		Stop,
		OutOfAmmo
	};

//Foward declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

//hold barrel proprietis and elebante 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GG_TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Fiering")
	void Fire();
	
	EFiringStatus GetFiringState();

	UFUNCTION(BlueprintCallable, Category = "Fiering")
	int32 GetRoundsLeft();

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);
	bool IsBarrelMoving();

	FVector AimDirection ;

	double LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float ReloadTimeInSecond = 3;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprints;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 50000;

	UPROPERTY(EditAnywhere, Category = "Firing")
	int32 RoundsLeft = 3;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reloading ;
};