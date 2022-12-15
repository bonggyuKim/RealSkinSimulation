// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GEometryPractice/Public/SoftBody.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoftBody() {}
// Cross Module References
	GEOMETRYPRACTICE_API UClass* Z_Construct_UClass_ASoftBody_NoRegister();
	GEOMETRYPRACTICE_API UClass* Z_Construct_UClass_ASoftBody();
	GEOMETRYSCRIPTINGEDITOR_API UClass* Z_Construct_UClass_AGeneratedDynamicMeshActor();
	UPackage* Z_Construct_UPackage__Script_GEometryPractice();
	GEOMETRYFRAMEWORK_API UClass* Z_Construct_UClass_UDynamicMesh_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	GEOMETRYFRAMEWORK_API UClass* Z_Construct_UClass_UDynamicMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASoftBody::execGetColNearInfo)
	{
		P_GET_OBJECT(UDynamicMesh,Z_Param_CollideMesh);
		P_GET_STRUCT(FVector,Z_Param_ColNearVector);
		P_GET_PROPERTY(FIntProperty,Z_Param_TN);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetColNearInfo(Z_Param_CollideMesh,Z_Param_ColNearVector,Z_Param_TN);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASoftBody::execSetMeshInfo)
	{
		P_GET_OBJECT(UDynamicMesh,Z_Param_TargetMesh);
		P_GET_OBJECT(UDynamicMeshComponent,Z_Param_UDMC);
		P_GET_PROPERTY(FFloatProperty,Z_Param_resolution);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMeshInfo(Z_Param_TargetMesh,Z_Param_UDMC,Z_Param_resolution);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASoftBody::execGetHitActorCenterInfo)
	{
		P_GET_OBJECT(UDynamicMesh,Z_Param_CollideMesh);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetHitActorCenterInfo(Z_Param_CollideMesh);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASoftBody::execMeshToSoftBody)
	{
		P_GET_OBJECT(UDynamicMesh,Z_Param_TargetMesh);
		P_GET_PROPERTY(FIntProperty,Z_Param_TriangleHitPoint);
		P_GET_PROPERTY(FFloatProperty,Z_Param_deltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDynamicMesh**)Z_Param__Result=P_THIS->MeshToSoftBody(Z_Param_TargetMesh,Z_Param_TriangleHitPoint,Z_Param_deltaTime);
		P_NATIVE_END;
	}
	static FName NAME_ASoftBody_OnRebuildSoftBodyMesh = FName(TEXT("OnRebuildSoftBodyMesh"));
	void ASoftBody::OnRebuildSoftBodyMesh(UDynamicMesh* TargetMesh)
	{
		SoftBody_eventOnRebuildSoftBodyMesh_Parms Parms;
		Parms.TargetMesh=TargetMesh;
		ProcessEvent(FindFunctionChecked(NAME_ASoftBody_OnRebuildSoftBodyMesh),&Parms);
	}
	void ASoftBody::StaticRegisterNativesASoftBody()
	{
		UClass* Class = ASoftBody::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetColNearInfo", &ASoftBody::execGetColNearInfo },
			{ "GetHitActorCenterInfo", &ASoftBody::execGetHitActorCenterInfo },
			{ "MeshToSoftBody", &ASoftBody::execMeshToSoftBody },
			{ "SetMeshInfo", &ASoftBody::execSetMeshInfo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics
	{
		struct SoftBody_eventGetColNearInfo_Parms
		{
			UDynamicMesh* CollideMesh;
			FVector ColNearVector;
			int32 TN;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CollideMesh;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ColNearVector;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TN;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::NewProp_CollideMesh = { "CollideMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventGetColNearInfo_Parms, CollideMesh), Z_Construct_UClass_UDynamicMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::NewProp_ColNearVector = { "ColNearVector", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventGetColNearInfo_Parms, ColNearVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::NewProp_TN = { "TN", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventGetColNearInfo_Parms, TN), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::NewProp_CollideMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::NewProp_ColNearVector,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::NewProp_TN,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASoftBody, nullptr, "GetColNearInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::SoftBody_eventGetColNearInfo_Parms), Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASoftBody_GetColNearInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASoftBody_GetColNearInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics
	{
		struct SoftBody_eventGetHitActorCenterInfo_Parms
		{
			UDynamicMesh* CollideMesh;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CollideMesh;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::NewProp_CollideMesh = { "CollideMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventGetHitActorCenterInfo_Parms, CollideMesh), Z_Construct_UClass_UDynamicMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventGetHitActorCenterInfo_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::NewProp_CollideMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASoftBody, nullptr, "GetHitActorCenterInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::SoftBody_eventGetHitActorCenterInfo_Parms), Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics
	{
		struct SoftBody_eventMeshToSoftBody_Parms
		{
			UDynamicMesh* TargetMesh;
			int32 TriangleHitPoint;
			float deltaTime;
			UDynamicMesh* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMesh;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TriangleHitPoint;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_deltaTime;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::NewProp_TargetMesh = { "TargetMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventMeshToSoftBody_Parms, TargetMesh), Z_Construct_UClass_UDynamicMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::NewProp_TriangleHitPoint = { "TriangleHitPoint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventMeshToSoftBody_Parms, TriangleHitPoint), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::NewProp_deltaTime = { "deltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventMeshToSoftBody_Parms, deltaTime), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventMeshToSoftBody_Parms, ReturnValue), Z_Construct_UClass_UDynamicMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::NewProp_TargetMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::NewProp_TriangleHitPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::NewProp_deltaTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASoftBody, nullptr, "MeshToSoftBody", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::SoftBody_eventMeshToSoftBody_Parms), Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASoftBody_MeshToSoftBody()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASoftBody_MeshToSoftBody_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::NewProp_TargetMesh = { "TargetMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventOnRebuildSoftBodyMesh_Parms, TargetMesh), Z_Construct_UClass_UDynamicMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::NewProp_TargetMesh,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Events" },
		{ "Comment", "/**\n\x09 * This event will be fired to notify the BP that the generated Mesh should\n\x09 * be rebuilt. GeneratedDynamicMeshActor BP subclasses should rebuild their\n\x09 * meshes on this event, instead of doing so directly from the Construction Script.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SoftBody.h" },
		{ "ToolTip", "This event will be fired to notify the BP that the generated Mesh should\nbe rebuilt. GeneratedDynamicMeshActor BP subclasses should rebuild their\nmeshes on this event, instead of doing so directly from the Construction Script." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASoftBody, nullptr, "OnRebuildSoftBodyMesh", nullptr, nullptr, sizeof(SoftBody_eventOnRebuildSoftBodyMesh_Parms), Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics
	{
		struct SoftBody_eventSetMeshInfo_Parms
		{
			UDynamicMesh* TargetMesh;
			UDynamicMeshComponent* UDMC;
			float resolution;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UDMC_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_UDMC;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_resolution;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_TargetMesh = { "TargetMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventSetMeshInfo_Parms, TargetMesh), Z_Construct_UClass_UDynamicMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_UDMC_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_UDMC = { "UDMC", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventSetMeshInfo_Parms, UDMC), Z_Construct_UClass_UDynamicMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_UDMC_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_UDMC_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_resolution = { "resolution", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SoftBody_eventSetMeshInfo_Parms, resolution), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_TargetMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_UDMC,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::NewProp_resolution,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASoftBody, nullptr, "SetMeshInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::SoftBody_eventSetMeshInfo_Parms), Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASoftBody_SetMeshInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASoftBody_SetMeshInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASoftBody);
	UClass* Z_Construct_UClass_ASoftBody_NoRegister()
	{
		return ASoftBody::StaticClass();
	}
	struct Z_Construct_UClass_ASoftBody_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EdgeCompliance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_EdgeCompliance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VolCompliance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VolCompliance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumSubsteps_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumSubsteps;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Gravity;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoftBody_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGeneratedDynamicMeshActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GEometryPractice,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASoftBody_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASoftBody_GetColNearInfo, "GetColNearInfo" }, // 2599340503
		{ &Z_Construct_UFunction_ASoftBody_GetHitActorCenterInfo, "GetHitActorCenterInfo" }, // 1395659866
		{ &Z_Construct_UFunction_ASoftBody_MeshToSoftBody, "MeshToSoftBody" }, // 2267987431
		{ &Z_Construct_UFunction_ASoftBody_OnRebuildSoftBodyMesh, "OnRebuildSoftBodyMesh" }, // 3327136371
		{ &Z_Construct_UFunction_ASoftBody_SetMeshInfo, "SetMeshInfo" }, // 3003669179
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftBody_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SoftBody.h" },
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftBody_Statics::NewProp_EdgeCompliance_MetaData[] = {
		{ "Category", "SoftBody" },
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoftBody_Statics::NewProp_EdgeCompliance = { "EdgeCompliance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftBody, EdgeCompliance), METADATA_PARAMS(Z_Construct_UClass_ASoftBody_Statics::NewProp_EdgeCompliance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftBody_Statics::NewProp_EdgeCompliance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftBody_Statics::NewProp_VolCompliance_MetaData[] = {
		{ "Category", "SoftBody" },
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASoftBody_Statics::NewProp_VolCompliance = { "VolCompliance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftBody, VolCompliance), METADATA_PARAMS(Z_Construct_UClass_ASoftBody_Statics::NewProp_VolCompliance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftBody_Statics::NewProp_VolCompliance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftBody_Statics::NewProp_NumSubsteps_MetaData[] = {
		{ "Category", "SoftBody" },
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ASoftBody_Statics::NewProp_NumSubsteps = { "NumSubsteps", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftBody, NumSubsteps), METADATA_PARAMS(Z_Construct_UClass_ASoftBody_Statics::NewProp_NumSubsteps_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftBody_Statics::NewProp_NumSubsteps_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoftBody_Statics::NewProp_Gravity_MetaData[] = {
		{ "Category", "SoftBody" },
		{ "ModuleRelativePath", "Public/SoftBody.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ASoftBody_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASoftBody, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_ASoftBody_Statics::NewProp_Gravity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftBody_Statics::NewProp_Gravity_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASoftBody_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftBody_Statics::NewProp_EdgeCompliance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftBody_Statics::NewProp_VolCompliance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftBody_Statics::NewProp_NumSubsteps,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoftBody_Statics::NewProp_Gravity,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoftBody_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoftBody>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASoftBody_Statics::ClassParams = {
		&ASoftBody::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASoftBody_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASoftBody_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASoftBody_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASoftBody_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASoftBody()
	{
		if (!Z_Registration_Info_UClass_ASoftBody.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASoftBody.OuterSingleton, Z_Construct_UClass_ASoftBody_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASoftBody.OuterSingleton;
	}
	template<> GEOMETRYPRACTICE_API UClass* StaticClass<ASoftBody>()
	{
		return ASoftBody::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoftBody);
	struct Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASoftBody, ASoftBody::StaticClass, TEXT("ASoftBody"), &Z_Registration_Info_UClass_ASoftBody, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASoftBody), 276700349U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_340911087(TEXT("/Script/GEometryPractice"),
		Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
