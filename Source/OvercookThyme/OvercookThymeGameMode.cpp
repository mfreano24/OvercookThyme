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
	//global timer for when the next order is due to come in

	if (activeOrders.Num() >= 5) {
		//dont make a new order, simply fire off the timer in 10 second ticks until this isnt true
		//better than an async while loop.
		UE_LOG(LogTemp, Warning, TEXT("Orders full!"));
		GetWorld()->GetTimerManager().SetTimer(OrderTimer, this, &AOvercookThymeGameMode::OnOrderTimer, 10.0f, false);
	}
	else {
		//make a new order
		UE_LOG(LogTemp, Warning, TEXT("Adding new order..."));
		AOrder* newOrder = GenerateRandomOrder(); //TODO: replace with a random generator
		activeOrders.Add(newOrder);
		GetWorld()->GetTimerManager().SetTimer(OrderTimer, this, &AOvercookThymeGameMode::OnOrderTimer, CalculateTimeToNextTicket(), false);
	}
}

float AOvercookThymeGameMode::CalculateTimeToNextTicket() 
{
	//TODO: come up with some progression curve that eventually caps out
	return 1.0f;
}

AOrder* AOvercookThymeGameMode::GenerateRandomOrder()
{
	Dish d;

	AOrder* newOrder = GetWorld()->SpawnActor<AOrder>();
	newOrder->dish = d;
	return newOrder;
}
