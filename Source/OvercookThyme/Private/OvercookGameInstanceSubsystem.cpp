// Fill out your copyright notice in the Description page of Project Settings.


#include "OvercookGameInstanceSubsystem.h"

void UOvercookGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	IdealTypeToDoneness.Add(Type::NONE, Doneness::NONE);

	CookingApplianceToMethod.Add("", Doneness::NONE);

	UE_LOG(LogTemp, Warning, TEXT("Initialize() called in GameInstance Subsystem"));
}
