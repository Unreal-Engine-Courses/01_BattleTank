// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATank* AIPawn = Cast<ATank>(GetPawn());
	if (AIPawn)
	{
		ATank* PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (PlayerPawn)
		{
			MoveToActor(PlayerPawn, AcceptanceRadius);

			AIPawn->AimAt(PlayerPawn->GetActorLocation());
			//AIPawn->Fire();
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No AI controlled tank found."));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Player Controlled tank found!"));
	}
}