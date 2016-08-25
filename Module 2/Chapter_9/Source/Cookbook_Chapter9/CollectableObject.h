// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CollectableObject.generated.h"

UCLASS()
class COOKBOOK_CHAPTER9_API ACollectableObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACollectableObject(const FObjectInitializer& ObjectInitializer);

	// Event called when something starts to overlaps the sphere collider
	UFUNCTION()
	void OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Our server function to update the score.
	UFUNCTION(Reliable, Server, WithValidation)
	void UpdateScore(int32 Amount);
	void UpdateScore_Implementation(int32 Amount);
	bool UpdateScore_Validate(int32 Amount);

};
