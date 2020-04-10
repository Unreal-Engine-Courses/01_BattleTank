// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
// Must be last include
#include "TankPlayerController.generated.h" 

// Forward Declarations
class ATank;

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

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	// Inherited
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.39999f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;
};
