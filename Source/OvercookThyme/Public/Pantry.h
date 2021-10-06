// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Station.h"
#include "Ingredient.h"
#include "Pantry.generated.h"

/**
 * 
 */
UCLASS()
class OVERCOOKTHYME_API APantry : public AStation
{
	GENERATED_BODY()

public:

	TArray<Ingredient> choices; //this should be exposed and initialized in code. how though!

	virtual void Interact(AOvercookThymeCharacter* Player) override;


	
};
