using UnrealBuildTool;

public class U06_ThirdPersonCPP : ModuleRules
{
	public U06_ThirdPersonCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{ 
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore" 
		});

		//PrivateDependencyModuleNames.AddRange(new string[] { "./" });
		PublicIncludePaths.Add(ModuleDirectory);
	}
}
