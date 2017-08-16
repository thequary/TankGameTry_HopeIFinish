// Fill out your copyright notice in the Description page of Project Settings.

#include "GG_Tanks.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationCheange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationCheange;
	SetRelativeRotation(FRotator(0, Rotation, 0));

	//UE_LOG(LogTemp, Warning, TEXT(" fownd on "));
}

