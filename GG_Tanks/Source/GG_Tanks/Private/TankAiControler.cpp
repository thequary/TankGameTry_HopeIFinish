// Fill out your copyright notice in the Description page of Project Settings.

#include "GG_Tanks.h"
#include "TankAiControler.h"

void ATankAiControler::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();

	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai can see -- %s"), *(PlayerTank->GetName()));
	}
	else { UE_LOG(LogTemp, Warning, TEXT("Not Poses!!")); }
}


ATank* ATankAiControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAiControler::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn)
	{
		return Cast<ATank>(PlayerPawn);
	}
	return  nullptr;
}
