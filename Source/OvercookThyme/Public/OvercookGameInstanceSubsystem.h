// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Ingredient.h"
#include "OvercookGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class OVERCOOKTHYME_API UOvercookGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	TMap<Type, Doneness> IdealTypeToDoneness;

	TMap<FString, Doneness> CookingApplianceToMethod;
	
};
