// Copyright Epic Games, Inc. All Rights Reserved.

#include "OvercookThymePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "OvercookThymeCharacter.h"
#include "Engine/World.h"

AOvercookThymePlayerController::AOvercookThymePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AOvercookThymePlayerController::BeginPlay()
{
	pawn = GetPawn();
}


void AOvercookThymePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	/*
	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
	*/


	//movement input
	pawn->AddMovementInput(moveDirection);
}

void AOvercookThymePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//InputComponent->BindAction("SetDestination", IE_Pressed, this, &AOvercookThymePlayerController::OnSetDestinationPressed);
	//InputComponent->BindAction("SetDestination", IE_Released, this, &AOvercookThymePlayerController::OnSetDestinationReleased);

	InputComponent->BindAxis("MoveForward", this, &AOvercookThymePlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AOvercookThymePlayerController::MoveRight);
}

void AOvercookThymePlayerController::OnResetVR()
{
	//UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AOvercookThymePlayerController::MoveToMouseCursor()
{

}

void AOvercookThymePlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AOvercookThymePlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();

	
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AOvercookThymePlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AOvercookThymePlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}


void AOvercookThymePlayerController::MoveForward(float scale)
{
	moveDirection.X = scale;
}


void AOvercookThymePlayerController::MoveRight(float scale)
{
	moveDirection.Y = scale;
}
