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


ATank* ATankPlayerControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

