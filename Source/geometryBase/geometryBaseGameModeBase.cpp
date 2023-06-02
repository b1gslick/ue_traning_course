// Copyright Epic Games, Inc. All Rights Reserved.

#include "geometryBaseGameModeBase.h"
#include "SandboxPawn.h"
#include "SandboxPlayerController.h"

AgeometryBaseGameModeBase::AgeometryBaseGameModeBase()
{
    DefaultPawnClass = ASandboxPawn::StaticClass();
    PlayerControllerClass = ASandboxPlayerController::StaticClass();
}