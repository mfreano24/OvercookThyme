// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OvercookThyme : ModuleRules
{
	public OvercookThyme(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
