// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ingredient.h"

/**
 * 
 */
class OVERCOOKTHYME_API Dish
{
public:
	TSet<Ingredient> ingredientsList;

	UPROPERTY(BlueprintReadWrite)
	int scoreValue;

	Dish();
	~Dish();

	UFUNCTION(BlueprintCallable)
	int CompareIngredients(TArray<Ingredient>& passIn);
};
