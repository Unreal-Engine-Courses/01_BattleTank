// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h" // Must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank* GetControlledTank() const;
	
	// Start the tank moving the barrel so that a shot would hit where crosswhere intersects the world
	void AimTowardsCrosshair();

	// Return an OUT Param OutHitLocation
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// Inherited
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
