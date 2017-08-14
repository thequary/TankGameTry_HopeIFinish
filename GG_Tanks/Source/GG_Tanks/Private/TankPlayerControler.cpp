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
		//UE_LOG(LogTemp, Warning, TEXT("hit - %s"), *HitLocation.ToString());

		//TODO Vom spune tank sa tinteasca locul "spuna locul"
	}
}

// Vom locatia liniei din ecran de pe teren VECTOR! Daca e adevarat returnam true
bool ATankPlayerControler::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Gasim pozitia Tintei
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLoaction = FVector2D(ViewportSizeX *CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("hit - %s"), *ScreenLoaction.ToString());
	// De-Project pozitia tintei din ecran in 3dspace Vector
	// LineTrace pe vectorul respectiv -- HIT!
	return true;
}