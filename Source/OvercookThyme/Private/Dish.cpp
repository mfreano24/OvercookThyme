// Fill out your copyright notice in the Description page of Project Settings.


#include "Dish.h"

Dish::Dish()
{
	ingredientsList = TSet<Ingredient>();
	scoreValue = 1000;
}

Dish::~Dish()
{
}

int Dish::CompareIngredients(TArray<Ingredient>& passIn)
{
	int n = passIn.Num();
	TSet<Ingredient> checkCopy = ingredientsList;
	int numCookedWrong = 0;
	for (int i = 0; i < n; i++)
	{
		if (!checkCopy.Contains(passIn[i])) {
			//Order made wrong! no points!
			return 0;
		}
		else {
			//remove passIn[i] from the ingredients list
			checkCopy.Remove(passIn[i]);
		}
	}
	int ret = scoreValue - numCookedWrong * 100;

	if (ret == scoreValue) {
		//perfect!
	}
	else if(ret < scoreValue){
		//you cooked wrong! tasted weird!
	}

	return ret;
}
