// Fill out your copyright notice in the Description page of Project Settings.

#include "Cookbook_Chapter9.h"
#include "CollectableObject.h"
#include "Engine.h" //GEngine


// Sets default values for this actor's properties
ACollectableObject::ACollectableObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Must be true for an Actor to replicate anything
	bReplicates = true;

	// Create a sphere collider for players to hit
	USphereComponent * SphereCollider = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComponent"));

	//Sets the size of our collider to have a radius of 64 units
	SphereCollider->InitSphereRadius(64.0f);

	//Sets the root of our object to be the sphere collider
	RootComponent = SphereCollider;

	// Makes it so that OnBeginOverlap will be called whenever something hits this.
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectableObject::OnBeginOverlap);
}

// Event called when something starts to overlaps the sphere collider
void ACollectableObject::OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// If I am the server
	if (Role == ROLE_Authority)
	{
		// Then a coin will be gained!
		UpdateScore(1);
		Destroy();
	}
}

// Do something here that modifies game state.
void ACollectableObject::UpdateScore_Implementation(int32 Amount)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "Collected!");
	}
}

// Optionally validate the request and return false if the function should not be run.
bool ACollectableObject::UpdateScore_Validate(int32 Amount)
{
	return true;
}
