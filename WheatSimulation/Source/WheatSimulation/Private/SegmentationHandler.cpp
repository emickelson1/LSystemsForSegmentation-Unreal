// Fill out your copyright notice in the Description page of Project Settings.

#include "SegmentationHandler.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


FString USegmentationHandler::GetCurrentTime() {
    std::time_t t = std::time(nullptr);         // current time
    std::tm localTime{};                        // make structure for local time values
    
    time_t now = time(0);
    tm tstruct;

    #if defined(_WIN32)
        localtime_s(&tstruct, &now);
    #else
        localtime_r(&now, &tstruct);
    #endif

    std::ostringstream oss;                     // string stream for formatting
    oss << std::put_time(&localTime, "%Y-%m-%d_%H:%M:%S");    // use put_time to format the date and time
    return FString(oss.str().c_str());
}

bool USegmentationHandler::ConvertArrayToSegmentation(TArray<int32> array, FString directory, FString currentTime) {
    // Get array dimensional size
    int size = sqrt(array.Num());

    // Array size validity check
    if (size * size != array.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("Array is not a perfect square."));
        return false;
    }

    // Get file path
    std::string filepath = std::string(TCHAR_TO_UTF8(*directory)) + "/" + std::string(TCHAR_TO_UTF8(*currentTime)) + "_label.png";

    // Convert TArray<int32> to uint8_t array
    TArray<uint8> pixelValues;
    int end = size * size;
    for (int i = 0; i < end; i++){
        int32 value = array[i];

        // Assuming value is in the range 0-255 for RGB
        uint8 r;
        uint8 g; 
        uint8 b;

        // Map the value to RGB colors
        switch(value) {
            case 0: // Background
                r = 0; g = 0; b = 0;
                break;
            case 1: // Head
                r = 132; g = 255; b = 50;
                break;
            case 2: // Stem
                r = 255; g = 132; b = 50;
                break;
            case 3: // Leaf
                r = 50; g = 255; b = 214;
                break;
            default: // Error
                r = 255; g = 255; b = 255;
                break;
        }

        pixelValues.Add(r);
        pixelValues.Add(g);
        pixelValues.Add(b);
    }

    stbi_write_png(
        filepath.c_str(),
        size, size, 3,
        pixelValues.GetData(),
        size * 3 // Stride in bytes: width * channels
    );

    return true;
}


bool USegmentationHandler::TakeScreenshot(int32 size, FString directory, FString currentTime) {
    // Get file path
    std::string filepath = std::string(TCHAR_TO_UTF8(*directory)) + "/" + std::string(TCHAR_TO_UTF8(*currentTime)) + "_image.png";
    
    // Take screenshot asynchronously on another thread
    AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [filepath]() {
        FScreenshotRequest::RequestScreenshot(FString(filepath.c_str()), false, false);
    });

    return true;
}