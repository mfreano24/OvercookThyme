// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Station.h"
#include "Carryable.h"
#include "Oven.generated.h"

/**
 * 
 */
UCLASS()
class OVERCOOKTHYME_API AOven : public AStation
{
	GENERATED_BODY()
public:
	AOven();
	~AOven();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
};
