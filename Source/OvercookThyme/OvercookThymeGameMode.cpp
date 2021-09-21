// Copyright Epic Games, Inc. All Rights Reserved.

#include "OvercookThymeGameMode.h"
#include "OvercookThymePlayerController.h"
#include "OvercookThymeCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"

AOvercookThymeGameMode::AOvercookThymeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AOvercookThymePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}


void AOvercookThymeGameMode::InitGameState() 
{
	Super::InitGameState();

	//make the timer

	GetWorld()->GetTimerManager().SetTimer(OrderTimer, this, &AOvercookThymeGameMode::OnOrderTimer, 3.0f, false);
}

void AOvercookThymeGameMode::OnOrderTimer()
{
	UE_LOG(LogTemp, Warning, TEXT("Timer fired off!"))
}

float AOvercookThymeGameMode::CalculateTimeToNextTicket() 
{
	//TODO: come up with some progression curve that eventually caps out
	return 1.0f;
}