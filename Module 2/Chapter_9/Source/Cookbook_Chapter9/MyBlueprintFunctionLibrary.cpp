// Fill out your copyright notice in the Description page of Project Settings.

#include "Cookbook_Chapter9.h"
#include "MyBlueprintFunctionLibrary.h"


FString UMyBlueprintFunctionLibrary::GetCopyrightNotice() 
{
	FString CopyrightNotice;

	//Get a string from a configuration file.
	GConfig->GetString(
		//Location of the string you want.
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		
		//Name of the string you want.
		TEXT("CopyrightNotice"),

		//Variable you want to put the string in.
		CopyrightNotice,
		
		//Which ini file do you want to grab from
		GGameIni
		);

	//Return the value of the variable ProjectVersion you've just set.
	return CopyrightNotice;
	
}
