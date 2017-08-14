// Fill out your copyright notice in the Description page of Project Settings.

#include "GG_Tanks.h"
#include "TankPlayerControler.h"

void ATankPlayerControler::BeginPlay()
{
	Super::BeginPlay();

	auto ControledTank = GetControlledTank();

	if (ControledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Posses!! %s"), *(ControledTank->GetName()));
	}
	else { UE_LOG(LogTemp, Warning, TEXT("Not Poses!!")); }
}

void ATankPlayerControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerControler::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; } // Verificam daca avem ControlerulTankului : nu avem nu procedam mai departe
	FVector HitLocation; // OutParameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("hit - %s"), *HitLocation.ToString());

		//TODO Vom spune tank sa tinteasca locul "spuna locul"
	}
}

// Vom locatia liniei din ecran de pe teren VECTOR! Daca e adevarat returnam true
bool ATankPlayerControler::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1, 0,0);
	return true;
}