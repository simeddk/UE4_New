// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "U04_Rifle/U04_RifleGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeU04_RifleGameModeBase() {}
// Cross Module References
	U04_RIFLE_API UClass* Z_Construct_UClass_AU04_RifleGameModeBase_NoRegister();
	U04_RIFLE_API UClass* Z_Construct_UClass_AU04_RifleGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_U04_Rifle();
// End Cross Module References
	void AU04_RifleGameModeBase::StaticRegisterNativesAU04_RifleGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AU04_RifleGameModeBase_NoRegister()
	{
		return AU04_RifleGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AU04_RifleGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AU04_RifleGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_U04_Rifle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AU04_RifleGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "U04_RifleGameModeBase.h" },
		{ "ModuleRelativePath", "U04_RifleGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AU04_RifleGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AU04_RifleGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AU04_RifleGameModeBase_Statics::ClassParams = {
		&AU04_RifleGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AU04_RifleGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AU04_RifleGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AU04_RifleGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AU04_RifleGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AU04_RifleGameModeBase, 3863599415);
	template<> U04_RIFLE_API UClass* StaticClass<AU04_RifleGameModeBase>()
	{
		return AU04_RifleGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AU04_RifleGameModeBase(Z_Construct_UClass_AU04_RifleGameModeBase, &AU04_RifleGameModeBase::StaticClass, TEXT("/Script/U04_Rifle"), TEXT("AU04_RifleGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AU04_RifleGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
