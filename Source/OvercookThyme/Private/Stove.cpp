// Fill out your copyright notice in the Description page of Project Settings.


#include "Stove.h"
#include "Runtime/Engine/Public/EngineGlobals.h"
#include "Kismet/GameplayStatics.h"
#include "../OvercookThymeGameMode.h"

AStove::AStove()
{
	Ingredient* testIngredient = new Ingredient(Type::Burger, Doneness::Raw, 12.0f);
	currItem = new Carryable(new Ingredient(Type::Burger, Doneness::Raw, 12.0f));

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.25f;
}

AStove::~AStove()
{

}

void AStove::BeginPlay()
{
	Super::BeginPlay();

	//subsystem stuff
	UOvercookGameInstanceSubsystem* cookSub = GetCookingSubsystem();

	cookSub->CookingApplianceToMethod.Add(this->GetClass()->GetName(), Doneness::Grilled);
	
}


void AStove::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Cyan, FString::Printf(TEXT("tick!")));
	//cook something over time.
	if (currItem != nullptr)
	{
		for (auto c : currItem->Ingredients) 
		{
			c->cookedValue += 100 * DeltaSeconds;

			if (c->doneness == Doneness::Raw && c->cookedValue >= 1000.0f)
			{
				UE_LOG(LogTemp, Warning, TEXT("INGREDIENT IS COOKED"));
				c->doneness = GetCookingSubsystem()->CookingApplianceToMethod[this->GetClass()->GetName()];
			}
			else if (c->cookedValue >= 1500.0f)
			{
				UE_LOG(LogTemp, Warning, TEXT("INGREDIENT IS BURNT"));
				c->doneness = Doneness::Burnt;
			}
		}
	}
}
