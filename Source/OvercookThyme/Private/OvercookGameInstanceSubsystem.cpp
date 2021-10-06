// Fill out your copyright notice in the Description page of Project Settings.


#include "OvercookGameInstanceSubsystem.h"

void UOvercookGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	IdealTypeToDoneness[Type::NONE] = Doneness::NONE;

	CookingApplianceToMethod[""] = Doneness::NONE;

	UE_LOG(LogTemp, Warning, TEXT("Initialize() called in GameInstance Subsystem"));
}
