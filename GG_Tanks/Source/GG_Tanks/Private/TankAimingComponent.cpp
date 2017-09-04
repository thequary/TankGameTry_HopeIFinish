// Fill out your copyright notice in the Description page of Project Settings.

#include "GG_Tanks.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	LastFireTime = FPlatformTime::Seconds();
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (RoundsLeft<=0) {
		FiringState = EFiringStatus::OutOfAmmo;
	}
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSecond) {
		FiringState = EFiringStatus::Reloading;
	}
	else if(IsBarrelMoving()) {
		FiringState = EFiringStatus::Aiming;
	}
	else
	{
		FiringState = EFiringStatus::Stop;
	}
}

EFiringStatus UTankAimingComponent::GetFiringState()
{
	return FiringState;
}

int32 UTankAimingComponent::GetRoundsLeft()
{
	return RoundsLeft;
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	auto BarrelFoward = Barrel->GetForwardVector();
	return !BarrelFoward.Equals(AimDirection, 0.01);
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.f,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution) {
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);
	}
	// UE_LOG(LogTemp, Warning, TEXT("%f fownd on %s"), Time, *Name); ///////////// UELOG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// If no solution found do nothing
}

void UTankAimingComponent::Fire()
{
	if (FiringState == EFiringStatus::Stop || FiringState == EFiringStatus::Aiming )
	{
		if (!ensure(Barrel)) { return; }
		if (!ensure(ProjectileBlueprints)) { return; }
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprints,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		RoundsLeft--;
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) // Get in the AimDirection
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
{
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - TurretRotator;

	if (FMath::Abs(DeltaRotator.Yaw)>180)
	{
		Turret->Rotate(-DeltaRotator.Yaw);
	}
	else {
		Turret->Rotate(DeltaRotator.Yaw);
	}
}


