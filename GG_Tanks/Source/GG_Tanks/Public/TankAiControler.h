// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAiControler.generated.h"

//Foward declaration
class ATank;


/**
 * 
 */
UCLASS()
class GG_TANKS_API ATankAiControler : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	// cat de aporoape poate AI sa se apropie de tank
	float AcceptanceRadius = 300;


};