// Copyright Epic Games, Inc. All Rights Reserved.

#include "RTSbfmeGameMode.h"
#include "RTSbfmePlayerController.h"
#include "RTSbfmeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARTSbfmeGameMode::ARTSbfmeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ARTSbfmePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}