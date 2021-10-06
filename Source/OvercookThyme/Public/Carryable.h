// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ingredient.h"

/**
 * 
 */
class OVERCOOKTHYME_API Carryable
{
public:
	Carryable();
	Carryable(Ingredient* single);
	~Carryable();

	TArray<Ingredient*> Ingredients;

	UPROPERTY(BlueprintReadWrite)
	bool bIsHeld;

	UFUNCTION(BlueprintCallable)
	void AddIngredient(Ingredient* i);
};
