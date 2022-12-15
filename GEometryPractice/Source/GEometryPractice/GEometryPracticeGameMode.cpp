// Copyright Epic Games, Inc. All Rights Reserved.

#include "GEometryPracticeGameMode.h"
#include "GEometryPracticeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGEometryPracticeGameMode::AGEometryPracticeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
