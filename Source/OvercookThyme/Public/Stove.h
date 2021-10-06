// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Station.h"
#include "Carryable.h"
#include "Stove.generated.h"

/**
 * 
 */
UCLASS()
class OVERCOOKTHYME_API AStove : public AStation
{
	GENERATED_BODY()
public:

	Carryable* currItem = nullptr;

	virtual void BeginPlay() override;

	virtual void Interact(AOvercookThymeCharacter* Player) override;

	virtual void Tick(float DeltaSeconds) override;
};
