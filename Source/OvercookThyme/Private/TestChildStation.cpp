// Fill out your copyright notice in the Description page of Project Settings.


#include "TestChildStation.h"

void ATestChildStation::Interact()
{
	Super::Interact();
	UE_LOG(LogTemp, Warning, TEXT("CHILD TEST STATION INTERACTED WITH: %s"), *GetName());
}