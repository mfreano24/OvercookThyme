// Fill out your copyright notice in the Description page of Project Settings.


#include "Dish.h"

Dish::Dish()
{
	ingredientsList = TArray<Ingredient>();
	scoreValue = 1000;
}

Dish::~Dish()
{
}

int Dish::CompareIngredients(TArray<Ingredient>& passIn)
{
	int n = passIn.Num();

	//this might have to be n^2 because its easier this way than to rewrite 
	TArray<Ingredient> checkCopy = ingredientsList;
	int numWrongState = 0;
	bool found = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < passIn.Num(); j++) {
			if (!found) {
				if (passIn[j] == checkCopy[i]) {
					found = true;

					if(passIn[j].doneness != checkCopy[i].doneness){
						numWrongState++;
					}
					passIn.RemoveAt(j);
				}
			}
		}
		found = false;
	}

	if (passIn.Num() > 0) {
		return 0;
	}
	
	int ret = 1000 - (100 * numWrongState);
	if (ret < 1000) {
		UE_LOG(LogTemp, Warning, TEXT("order ALMOST right: %d"), ret);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PERFECT ORDER: %d"), ret);
	}

	return ret;

}

void Dish::ConstructFromDataTable(int rowNum)
{
	
}
