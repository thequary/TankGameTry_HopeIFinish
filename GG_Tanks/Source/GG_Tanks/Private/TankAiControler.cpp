// Fill out your copyright notice in the Description page of Project Settings.

#include "GG_Tanks.h"
#include "TankAimingComponent.h"
#include "TankAiControler.h"

void ATankAiControler::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAiControler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControledTank = GetPawn();

	if (!ensure(PlayerTank && ControledTank)) { return; }
		
	MoveToActor(PlayerTank, AcceptanceRadius);
		
	auto AimingComponent = ControledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringStatus::Stop) 
	{
		AimingComponent->Fire(); //TODO dont fire every frame
	}
}

