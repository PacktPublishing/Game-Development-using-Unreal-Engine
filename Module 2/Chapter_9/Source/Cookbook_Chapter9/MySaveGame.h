// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class COOKBOOK_CHAPTER9_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
	
	public:

		UPROPERTY(VisibleAnywhere, Category = Basic)
		FVector PlayerPosition;

		UPROPERTY(VisibleAnywhere, Category = Basic)
		FRotator PlayerRotation;
	
};
