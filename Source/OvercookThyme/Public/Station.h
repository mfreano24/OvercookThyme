// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Station.generated.h"

UCLASS()
class OVERCOOKTHYME_API AStation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category="Collision")
	class UBoxComponent* Trigger;

	UPROPERTY(EditDefaultsOnly, Category = "Collision")
	class UStaticMeshComponent* Mesh;

public:

	UFUNCTION(BlueprintCallable)
	virtual void Interact();

	UFUNCTION(BlueprintCallable)
	void OnPlayerOverlap(UPrimitiveComponent* comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable)
	void OnPlayerExitTrigger(UPrimitiveComponent* comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
