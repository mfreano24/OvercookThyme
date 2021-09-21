// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OvercookThymeGameMode.generated.h"

UCLASS(minimalapi)
class AOvercookThymeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOvercookThymeGameMode();

	UPROPERTY()
	int OrdersFulfilled;

	UPROPERTY()
	FTimerHandle OrderTimer;

	virtual void InitGameState() override;

	UFUNCTION()
	void OnOrderTimer();

	UFUNCTION()
	float CalculateTimeToNextTicket();
	
};



