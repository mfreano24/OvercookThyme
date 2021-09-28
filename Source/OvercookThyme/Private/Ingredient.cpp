// Fill out your copyright notice in the Description page of Project Settings.


#include "Ingredient.h"

Ingredient::Ingredient()
{
	type = Type::NONE;
	doneness = Doneness::Raw;
	cookedValue = 0.0f;

}

Ingredient::Ingredient(Type t, Doneness d, float cook)
{
	type = t;
	doneness = d;
	cookedValue = cook;
}

Ingredient::~Ingredient()
{
}

bool Ingredient::operator==(Ingredient& b)
{
	//they are equal if they have the same type- losing points for cooking things wrong is calculated later so we dont need to compare that
	return this->type == b.type;

}