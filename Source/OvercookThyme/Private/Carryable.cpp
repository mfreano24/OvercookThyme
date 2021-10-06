// Fill out your copyright notice in the Description page of Project Settings.


#include "Carryable.h"

Carryable::Carryable()
{
	Ingredients = TArray<Ingredient*>();
	bIsHeld = false;
}

Carryable::Carryable(Ingredient* single)
{
	Ingredients = TArray<Ingredient*>();
	bIsHeld = false;
	Ingredients.Add(single);
}

Carryable::~Carryable()
{
}

void Carryable::AddIngredient(Ingredient* i)
{

}
