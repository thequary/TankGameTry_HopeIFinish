// Fill out your copyright notice in the Description page of Project Settings.

#include "GG_Tanks.h"
#include "Tank.h"
#include "TankAiControler.h"

void ATankAiControler::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAiControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto Tank = Cast<ATank>(GetPawn());
	if (ensure(PlayerTank))
	{
		// TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards the player
		if (PlayerTank) Tank->AimAt(PlayerTank->GetActorLocation());
		
		//Tank fier every frame
		Tank->Fire(); //TODO dont fire every frame
	}
}

