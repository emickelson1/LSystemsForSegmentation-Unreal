// #include "AssetRegistryModule.h"
// #include "Engine/StaticMesh.h"
// #include "FindWheatMeshes.h"

// TArray<FSoftObjectPath> FindWheatMeshes(const FString& Domain)
// {
//     TArray<FSoftObjectPath> Result;

//     // Convert Windows path to Unreal path
//     FString SearchPath = FString::Printf(TEXT("/Game/WheatMeshes/%s"), *Domain);

//     // Get Asset Registry
//     FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
//     IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

//     // Set up filter
//     FARFilter Filter;
//     Filter.PackagePaths.Add(*SearchPath);
//     Filter.ClassNames.Add(UStaticMesh::StaticClass()->GetFName());
//     Filter.bRecursivePaths = false; // Only look in the specific domain folder
//     Filter.bRecursiveClasses = true;

//     TArray<FAssetData> AssetDataList;
//     AssetRegistry.GetAssets(Filter, AssetDataList);

//     for (const FAssetData& AssetData : AssetDataList)
//     {
//         const FString& Name = AssetData.AssetName.ToString();
//         if (Name.StartsWith("Wheat_"))
//         {
//             FSoftObjectPath SoftRef = AssetData.ToSoftObjectPath();
//             Result.Add(SoftRef);

//             // Optional: Log found assets
//             UE_LOG(LogTemp, Log, TEXT("Found mesh: %s"), *SoftRef.ToString());
//         }
//     }

//     return Result;
// }
