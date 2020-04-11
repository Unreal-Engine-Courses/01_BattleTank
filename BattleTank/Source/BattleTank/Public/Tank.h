// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class UTankAimingComponent;
class UTankBarrel;
class UTankMovementComponent;
class UTankTrack;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category="Setup")
	void Fire();

	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetTurretReference(UTankTurret* TurretToSet);

	/*UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetLeftTrackReference(UTankTrack* TrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetRightTrackReference(UTankTrack* TrackToSet);*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category="Setup")
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 5.f;

	float LastFireTime = 0;
};
