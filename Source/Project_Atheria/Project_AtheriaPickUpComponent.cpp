// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_AtheriaPickUpComponent.h"

UProject_AtheriaPickUpComponent::UProject_AtheriaPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UProject_AtheriaPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UProject_AtheriaPickUpComponent::OnSphereBeginOverlap);
}

void UProject_AtheriaPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AProject_AtheriaCharacter* Character = Cast<AProject_AtheriaCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
