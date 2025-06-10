// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WheatMeshLoader.generated.h"

/**
 * 
 */
UCLASS()
class WHEATSIMULATION_API UWheatMeshLoader : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Mesh Loading")
	TArray<TSoftObjectPtr<UStaticMesh>> LoadWheatMeshes(const FString& Domain);
};
