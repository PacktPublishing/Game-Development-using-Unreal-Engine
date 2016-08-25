// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "Cookbook_Chapter9GameMode.generated.h"

UCLASS(minimalapi)
class ACookbook_Chapter9GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ACookbook_Chapter9GameMode();
	void StartMatch();
};

