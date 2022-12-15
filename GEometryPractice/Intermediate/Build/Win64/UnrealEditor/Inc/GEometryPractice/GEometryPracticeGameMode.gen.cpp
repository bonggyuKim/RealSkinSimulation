// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GEometryPractice/GEometryPracticeGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGEometryPracticeGameMode() {}
// Cross Module References
	GEOMETRYPRACTICE_API UClass* Z_Construct_UClass_AGEometryPracticeGameMode_NoRegister();
	GEOMETRYPRACTICE_API UClass* Z_Construct_UClass_AGEometryPracticeGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_GEometryPractice();
// End Cross Module References
	void AGEometryPracticeGameMode::StaticRegisterNativesAGEometryPracticeGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGEometryPracticeGameMode);
	UClass* Z_Construct_UClass_AGEometryPracticeGameMode_NoRegister()
	{
		return AGEometryPracticeGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGEometryPracticeGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGEometryPracticeGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GEometryPractice,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGEometryPracticeGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GEometryPracticeGameMode.h" },
		{ "ModuleRelativePath", "GEometryPracticeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGEometryPracticeGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGEometryPracticeGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGEometryPracticeGameMode_Statics::ClassParams = {
		&AGEometryPracticeGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGEometryPracticeGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGEometryPracticeGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGEometryPracticeGameMode()
	{
		if (!Z_Registration_Info_UClass_AGEometryPracticeGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGEometryPracticeGameMode.OuterSingleton, Z_Construct_UClass_AGEometryPracticeGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGEometryPracticeGameMode.OuterSingleton;
	}
	template<> GEOMETRYPRACTICE_API UClass* StaticClass<AGEometryPracticeGameMode>()
	{
		return AGEometryPracticeGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGEometryPracticeGameMode);
	struct Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGEometryPracticeGameMode, AGEometryPracticeGameMode::StaticClass, TEXT("AGEometryPracticeGameMode"), &Z_Registration_Info_UClass_AGEometryPracticeGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGEometryPracticeGameMode), 3605138170U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeGameMode_h_3345713174(TEXT("/Script/GEometryPractice"),
		Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
