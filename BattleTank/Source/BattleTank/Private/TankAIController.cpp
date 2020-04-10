// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetAIControlledTank();

	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI controlled tanks found."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found AI Tank: %s"), *AIControlledTank->GetName());
	}
}