// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FLinearColor;
#ifdef U04_RIFLE_CPlayer_generated_h
#error "CPlayer.generated.h already included, missing '#pragma once' in CPlayer.h"
#endif
#define U04_RIFLE_CPlayer_generated_h

#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_SPARSE_DATA
#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetBodyColor);


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetBodyColor);


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_EVENT_PARMS
#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_CALLBACK_WRAPPERS
#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACPlayer(); \
	friend struct Z_Construct_UClass_ACPlayer_Statics; \
public: \
	DECLARE_CLASS(ACPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/U04_Rifle"), NO_API) \
	DECLARE_SERIALIZER(ACPlayer) \
	virtual UObject* _getUObject() const override { return const_cast<ACPlayer*>(this); }


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_INCLASS \
private: \
	static void StaticRegisterNativesACPlayer(); \
	friend struct Z_Construct_UClass_ACPlayer_Statics; \
public: \
	DECLARE_CLASS(ACPlayer, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/U04_Rifle"), NO_API) \
	DECLARE_SERIALIZER(ACPlayer) \
	virtual UObject* _getUObject() const override { return const_cast<ACPlayer*>(this); }


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACPlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACPlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACPlayer(ACPlayer&&); \
	NO_API ACPlayer(const ACPlayer&); \
public:


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACPlayer(ACPlayer&&); \
	NO_API ACPlayer(const ACPlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACPlayer)


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CrossDotWidgetClass() { return STRUCT_OFFSET(ACPlayer, CrossDotWidgetClass); } \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(ACPlayer, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(ACPlayer, Camera); }


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_8_PROLOG \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_EVENT_PARMS


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_PRIVATE_PROPERTY_OFFSET \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_SPARSE_DATA \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_RPC_WRAPPERS \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_CALLBACK_WRAPPERS \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_INCLASS \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define U04_Rifle_Source_U04_Rifle_CPlayer_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_PRIVATE_PROPERTY_OFFSET \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_SPARSE_DATA \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_CALLBACK_WRAPPERS \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_INCLASS_NO_PURE_DECLS \
	U04_Rifle_Source_U04_Rifle_CPlayer_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> U04_RIFLE_API UClass* StaticClass<class ACPlayer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID U04_Rifle_Source_U04_Rifle_CPlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
