// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="Setup")
    void SetThrottle(float Throttle);

private:
    // Max force per track, in Newtons
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float TrackMaxDrivingForce = 400000.f; // Assume 40 ton tank and 1g acceleration
};
