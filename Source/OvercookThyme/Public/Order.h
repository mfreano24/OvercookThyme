// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dish.h"
#include "Order.generated.h"

UCLASS()
class OVERCOOKTHYME_API AOrder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	Dish dish;

	UPROPERTY(BlueprintReadWrite)
	float orderTime;

	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
