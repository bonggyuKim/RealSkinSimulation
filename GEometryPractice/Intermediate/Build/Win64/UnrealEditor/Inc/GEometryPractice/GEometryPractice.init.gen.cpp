// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGEometryPractice_init() {}
	GEOMETRYPRACTICE_API UFunction* Z_Construct_UDelegateFunction_GEometryPractice_OnPickUp__DelegateSignature();
	GEOMETRYPRACTICE_API UFunction* Z_Construct_UDelegateFunction_GEometryPractice_OnUseItem__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GEometryPractice;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GEometryPractice()
	{
		if (!Z_Registration_Info_UPackage__Script_GEometryPractice.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_GEometryPractice_OnPickUp__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GEometryPractice_OnUseItem__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/GEometryPractice",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x2F2BDA38,
				0xDA60D8E2,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GEometryPractice.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_GEometryPractice.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GEometryPractice(Z_Construct_UPackage__Script_GEometryPractice, TEXT("/Script/GEometryPractice"), Z_Registration_Info_UPackage__Script_GEometryPractice, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x2F2BDA38, 0xDA60D8E2));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
