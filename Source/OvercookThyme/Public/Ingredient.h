// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

enum class Type {
	Burger,
	Bread,
	NONE
	//List here the types of ingredients we might have in the game, to be discussed in design meeting
};

enum class Doneness {
	Raw,
	Grilled,
	Baked,
	Burnt,
	NONE
};

class OVERCOOKTHYME_API Ingredient
{

public:

	UPROPERTY(BlueprintReadWrite)
	Type type;

	UPROPERTY(BlueprintReadWrite)
	Doneness doneness;

	UPROPERTY(BlueprintReadWrite)
	float cookedValue;

	Ingredient();
	Ingredient(Type t, Doneness d, float cook);
	~Ingredient();

	bool operator==(Ingredient& b);




};
