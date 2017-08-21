// Fill out your copyright notice in the Description page of Project Settings.

#include "GG_Tanks.h"
#include "Tank.h"
#include "TankAiControler.h"

void ATankAiControler::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAiControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		GetControlledTank()->Fire();
	}
}

ATank* ATankAiControler::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiControler::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; } // Note the !, very important
	return Cast<ATank>(PlayerPawn);
}