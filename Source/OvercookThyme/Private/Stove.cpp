// Fill out your copyright notice in the Description page of Project Settings.


#include "Stove.h"
#include "Runtime/Engine/Public/EngineGlobals.h"

void AStove::BeginPlay()
{
	Super::BeginPlay();
	Ingredient* testIngredient = new Ingredient(Type::Burger, Doneness::Raw, 12.0f);
	currItem = new Carryable(new Ingredient(Type::Burger, Doneness::Raw, 12.0f));


	GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Red, FString::Printf(TEXT("item: %s, %s, %f"),
		currItem->Ingredients[0]->type, currItem->Ingredients[0]->doneness, currItem->Ingredients[0]->cookedValue));
}

void AStove::Interact(AOvercookThymeCharacter* Player)
{
	Super::Interact(Player);

	if (currItem == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("curr item is nullptr"));
		//need to make sure the player has an item
		if (Player->currCarry != nullptr && currItem == nullptr) {
			Carryable* ret = Player->RemoveCarryable();
			currItem = ret;

			GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Red, FString::Printf(TEXT("Placed on the stove: %s, %s, %f"),
				currItem->Ingredients[0]->type, currItem->Ingredients[0]->doneness, currItem->Ingredients[0]->cookedValue));
			
		}
	}
	else {
		
		if (Player->currCarry == nullptr && currItem != nullptr) {
			Player->PickUpCarryable(currItem);
			currItem = nullptr;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("PLAYER item is NOT nullptr"));
		}
	}

	//set the tick interval
	if (currItem == nullptr) {
		PrimaryActorTick.bCanEverTick = false;
	}
	else {
		PrimaryActorTick.bCanEverTick = true;
		PrimaryActorTick.TickInterval = 0.25f;
	}
}

void AStove::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//cook something over time.
	if (currItem != nullptr)
	{
		for (auto c : currItem->Ingredients) {
			c->cookedValue += 100 * DeltaSeconds;
		}
	}
}
