// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "RaycastHandler.generated.h"

/**
 * 
 */
UCLASS()
class WHEATSIMULATION_API URaycastHandler : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Raycast")
	bool PerformRaycast();
	// bool PerformRaycast(const FVector& Start, const FVector& End, TArray<AActor*> ActorsToIgnore = TArray<AActor*>(), ECollisionChannel TraceChannel = ECC_Visibility);
	
};
