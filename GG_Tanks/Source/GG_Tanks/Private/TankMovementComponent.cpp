// Fill out your copyright notice in the Description page of Project Settings.

#include "GG_Tanks.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankFoward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiFowardIntention = MoveVelocity.GetSafeNormal();

	auto FowardThrow = FVector::DotProduct(AiFowardIntention, TankFoward);
	IntendMoveFoward(FowardThrow);


	auto TurnRight = FVector::CrossProduct(TankFoward, AiFowardIntention).Z;
	IntendTurnRight(TurnRight);
	
	
	//UE_LOG(LogTemp, Warning, TEXT("%s fownd on %s"),*Name, *AiFowardIntention);
}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack*RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveFoward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}



void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

