// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GEometryPractice : ModuleRules
{
	public GEometryPractice(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{ 
			"DynamicMesh",
            "PhysicsCore",
            "RenderCore",
            "Core",
			"InputCore",
			"HeadMountedDisplay",
			"GeometryCore",
			"GeometryFramework",
		}
		);

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "CoreUObject",
            "Engine",
            "MeshDescription",
            "StaticMeshDescription",
            "MeshConversion",
            "GeometryAlgorithms",
            "ModelingOperators",
            "ModelingComponents"
        }
        );
    }
}
