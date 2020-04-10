// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"

ATank* ATankAIController::GetAIControlledTank() const
{
	auto AIPawn = GetPawn();
	return (AIPawn) ? Cast<ATank>(AIPawn) : nullptr;
}

ATank* ATankAIController::GetPlayerControlledTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return (PlayerPawn) ? Cast<ATank>(PlayerPawn) : nullptr;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*auto AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI controlled tanks found."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found AI Tank: %s"), *AIControlledTank->GetName());
	}*/

	// Find the Player Controller
	auto PlayerControlledTank = GetPlayerControlledTank();
	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No player controlled tank found."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found Player Tank: %s"), *PlayerControlledTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerControlledTank())
	{
		if (GetAIControlledTank())
		{
			GetAIControlledTank()->AimAt(GetPlayerControlledTank()->GetActorLocation());
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No AI controlled tank found."));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Player Controlled tank found!"));
	}
}