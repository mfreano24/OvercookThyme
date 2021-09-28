// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "Ingredient.h"

/**
 * 
 */
class OVERCOOKTHYME_API Dish
{
public:
	UPROPERTY(BlueprintReadOnly)
	TArray<Ingredient> ingredientsList;

	UPROPERTY(BlueprintReadWrite)
	int scoreValue;

	Dish();
	~Dish();

	UFUNCTION(BlueprintCallable)
	int CompareIngredients(TArray<Ingredient>& passIn);

	UFUNCTION(BlueprintCallable)
	void ConstructFromDataTable(int rowNum);

	
};
