// Fill out your copyright notice in the Description page of Project Settings.


#include "WheatMeshLoader.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/StaticMesh.h"


TArray<TSoftObjectPtr<UStaticMesh>> UWheatMeshLoader::LoadWheatMeshes(const FString& Domain) {
    TArray<TSoftObjectPtr<UStaticMesh>> MeshReferences;

    // Construct the base path, e.g., "/Game/WheatMeshes/YourDomain"
    FString BasePath = FString::Printf(TEXT("/Game/Wheat/%s"), *Domain);

    // Get the Asset Registry
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

    // Prepare the filter
    FARFilter Filter;
    Filter.ClassNames.Add(UStaticMesh::StaticClass()->GetFName());
    Filter.PackagePaths.Add(*BasePath);
    Filter.bRecursivePaths = true;

    // Query the assets
    TArray<FAssetData> AssetDataList;
    AssetRegistry.GetAssets(Filter, AssetDataList);

    for (const FAssetData& AssetData : AssetDataList) {
        MeshReferences.Add(TSoftObjectPtr<UStaticMesh>(AssetData.ToSoftObjectPath()));
    }

    return MeshReferences;
}