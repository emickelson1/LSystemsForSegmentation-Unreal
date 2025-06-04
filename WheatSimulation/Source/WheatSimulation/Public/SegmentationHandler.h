// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SegmentationHandler.generated.h"

/**
 * 
 */
UCLASS()
class WHEATSIMULATION_API USegmentationHandler : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Raycast")
	FString GetCurrentTime();

	UFUNCTION(BlueprintCallable, Category = "Raycast")
	bool ConvertArrayToSegmentation(TArray<int32> array, FString directory, FString currentTime);

	UFUNCTION(BlueprintCallable, Category = "Raycast")
	bool TakeScreenshot(int32 size, FString directory, FString currentTime);
};
