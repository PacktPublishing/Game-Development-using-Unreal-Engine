// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Cookbook_Chapter9.h"
#include "Cookbook_Chapter9GameMode.h"
#include "Cookbook_Chapter9Character.h"
#include "Engine.h" //GEngine
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"

ACookbook_Chapter9GameMode::ACookbook_Chapter9GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ACookbook_Chapter9GameMode::StartMatch()
{
	Super::StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "Hello World!");
	}
}
