// Fill out your copyright notice in the Description page of Project Settings.

#include "SegmentationHandler.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#include <ctime>
#include <iostream>
#include <iomanip>

bool ConvertArrayToSegmentation(TArray<int32> Array, const char* SaveDirectory) {
    // Get array dimensional size
    int size = sqrt(Array.Num());

    // Array size validity check
    if (size * size != Array.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("Array is not a perfect square."));
        return false;
    }

    // Get datetime
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S_label.png");
    std::string filenameStr = oss.str();
    const char* filename = filenameStr.c_str();

    // Convert the array to a PNG image and save it
    TArray<uint8> ImageData;

    bool arrayToPng(const uint8_t* pixels, int width, int height, const char* filename) {
        int channels = 3; // RGB
        int stride_bytes = width * channels;

        int result = stbi_write_png(filename, width, height, channels, pixels, stride_bytes);

        return result != 0;
    };

    int result = stbi_write_png(
        SaveDirectory,
        size, size, 3,
        // const void *data?
        size * sizeof(int32) // Stride in bytes 
    );
}