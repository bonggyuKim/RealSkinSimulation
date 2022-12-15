// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef GEOMETRYPRACTICE_GEometryPracticeProjectile_generated_h
#error "GEometryPracticeProjectile.generated.h already included, missing '#pragma once' in GEometryPracticeProjectile.h"
#endif
#define GEOMETRYPRACTICE_GEometryPracticeProjectile_generated_h

#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_SPARSE_DATA
#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGEometryPracticeProjectile(); \
	friend struct Z_Construct_UClass_AGEometryPracticeProjectile_Statics; \
public: \
	DECLARE_CLASS(AGEometryPracticeProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GEometryPractice"), NO_API) \
	DECLARE_SERIALIZER(AGEometryPracticeProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAGEometryPracticeProjectile(); \
	friend struct Z_Construct_UClass_AGEometryPracticeProjectile_Statics; \
public: \
	DECLARE_CLASS(AGEometryPracticeProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GEometryPractice"), NO_API) \
	DECLARE_SERIALIZER(AGEometryPracticeProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGEometryPracticeProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGEometryPracticeProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGEometryPracticeProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGEometryPracticeProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGEometryPracticeProjectile(AGEometryPracticeProjectile&&); \
	NO_API AGEometryPracticeProjectile(const AGEometryPracticeProjectile&); \
public:


#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGEometryPracticeProjectile(AGEometryPracticeProjectile&&); \
	NO_API AGEometryPracticeProjectile(const AGEometryPracticeProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGEometryPracticeProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGEometryPracticeProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGEometryPracticeProjectile)


#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_12_PROLOG
#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_SPARSE_DATA \
	FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_RPC_WRAPPERS \
	FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_INCLASS \
	FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_SPARSE_DATA \
	FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GEOMETRYPRACTICE_API UClass* StaticClass<class AGEometryPracticeProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_GEometryPractice_Source_GEometryPractice_GEometryPracticeProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
