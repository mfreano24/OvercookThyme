// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Station.h"
#include "TestChildStation.generated.h"

/**
 * 
 */
UCLASS()
class OVERCOOKTHYME_API ATestChildStation : public AStation
{
	GENERATED_BODY()

public: 
	virtual void Interact(AOvercookThymeCharacter* Player) override;
	
};
