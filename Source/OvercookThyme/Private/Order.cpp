// Fill out your copyright notice in the Description page of Project Settings.


#include "Order.h"

// Sets default values
AOrder::AOrder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AOrder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

