// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAiControler.generated.h"

/**
 * 
 */
UCLASS()
class GG_TANKS_API ATankAiControler : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
		
private:
	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
	
};
