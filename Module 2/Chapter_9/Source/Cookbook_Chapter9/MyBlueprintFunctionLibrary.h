// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class COOKBOOK_CHAPTER9_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public: 
	// Create the Blueprint node and give it a name and category. The next line is the function that is associated with this
	UFUNCTION(BlueprintPure, meta = (FriendlyName = "Copyright Notice", CompactNodeTitle = "Copyright Notice"), Category = "Project Settings")
	static FString GetCopyrightNotice();
	
};
