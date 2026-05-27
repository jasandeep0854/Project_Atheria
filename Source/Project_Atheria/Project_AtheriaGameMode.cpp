// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_AtheriaGameMode.h"
#include "Project_AtheriaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_AtheriaGameMode::AProject_AtheriaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
