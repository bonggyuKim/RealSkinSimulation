// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDynamicMesh;
class UDynamicMeshComponent;
#ifdef GEOMETRYPRACTICE_SoftBody_generated_h
#error "SoftBody.generated.h already included, missing '#pragma once' in SoftBody.h"
#endif
#define GEOMETRYPRACTICE_SoftBody_generated_h

#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_SPARSE_DATA
#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetColNearInfo); \
	DECLARE_FUNCTION(execSetMeshInfo); \
	DECLARE_FUNCTION(execGetHitActorCenterInfo); \
	DECLARE_FUNCTION(execMeshToSoftBody);


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetColNearInfo); \
	DECLARE_FUNCTION(execSetMeshInfo); \
	DECLARE_FUNCTION(execGetHitActorCenterInfo); \
	DECLARE_FUNCTION(execMeshToSoftBody);


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_EVENT_PARMS \
	struct SoftBody_eventOnRebuildSoftBodyMesh_Parms \
	{ \
		UDynamicMesh* TargetMesh; \
	};


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_CALLBACK_WRAPPERS
#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASoftBody(); \
	friend struct Z_Construct_UClass_ASoftBody_Statics; \
public: \
	DECLARE_CLASS(ASoftBody, AGeneratedDynamicMeshActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GEometryPractice"), NO_API) \
	DECLARE_SERIALIZER(ASoftBody)


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_INCLASS \
private: \
	static void StaticRegisterNativesASoftBody(); \
	friend struct Z_Construct_UClass_ASoftBody_Statics; \
public: \
	DECLARE_CLASS(ASoftBody, AGeneratedDynamicMeshActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GEometryPractice"), NO_API) \
	DECLARE_SERIALIZER(ASoftBody)


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASoftBody(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASoftBody) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASoftBody); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASoftBody); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASoftBody(ASoftBody&&); \
	NO_API ASoftBody(const ASoftBody&); \
public:


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASoftBody(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASoftBody(ASoftBody&&); \
	NO_API ASoftBody(const ASoftBody&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASoftBody); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASoftBody); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASoftBody)


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_24_PROLOG \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_EVENT_PARMS


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_SPARSE_DATA \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_RPC_WRAPPERS \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_CALLBACK_WRAPPERS \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_INCLASS \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_SPARSE_DATA \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_CALLBACK_WRAPPERS \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_INCLASS_NO_PURE_DECLS \
	FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h_27_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SoftBody."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GEOMETRYPRACTICE_API UClass* StaticClass<class ASoftBody>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GEometryPractice_Source_GEometryPractice_Public_SoftBody_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
