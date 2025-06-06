// Fill out your copyright notice in the Description page of Project Settings.

#include "RaycastHandler.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


TArray<int32> GetSegmentationArray(int32 resolution) {
    // Initialize array
    TArray<int32> segmentationArray;

    // Initialize constant parameters for the async linetrace
    EAsyncTraceType traceType = EAsyncTraceType::LineTraceSingleByChannel;
    ECollisionChannel collisionChannel = ECollisionChannel::ECC_Visibility;

    FCollisionQueryParams collisionParams;
    collisionParams.bTraceComplex = true; // Enable complex collision
    collisionParams.bReturnPhysicalMaterial = false; // Do not return physical material
    collisionParams.bIgnoreBlocks = false; // Ignore blocking objects
    collisionParams.bReturnFaceIndex = true; // Return face index

    // Loop through the resolution to fill the array
    for (int y = 0; y < resolution; y++){
        for (int x = 0; x < resolution; x++){
            // Initialize parameters for the async linetrace

            FTraceHandle AsyncLineTraceByChannel(
                traceType,
                //start,
                //end,
                collisionChannel,
                &collisionParams,
                &responseParams,
            )
        }
    }
}