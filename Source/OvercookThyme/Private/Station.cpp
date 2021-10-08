// Fill out your copyright notice in the Description page of Project Settings.


#include "Station.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "../OvercookThymeCharacter.h"

// Sets default values
AStation::AStation()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetCollisionResponseToAllChannels(ECR_Ignore);
	Trigger->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	Trigger->SetBoxExtent(FVector(25.0f));
	Trigger->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void AStation::BeginPlay()
{
	Super::BeginPlay();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AStation::OnPlayerOverlap);

	Trigger->OnComponentEndOverlap.AddDynamic(this, &AStation::OnPlayerExitTrigger);
}


void AStation::Interact(AOvercookThymeCharacter* Player)
{
	if (currItem == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("curr item is nullptr"));
		//need to make sure the player has an item
		if (Player->currCarry != nullptr && currItem == nullptr) {
			if (Player->currCarry->Ingredients.Num() == 1) {
				//TENTATIVE- MAY REMOVE IF TOO CONFUSING FOR A PLAYER
				Carryable* ret = Player->RemoveCarryable();
				currItem = ret;
			}

		}
	}
	else {

		if (Player->currCarry == nullptr && currItem != nullptr)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Orange,
				//FString::Printf(TEXT("Picked burger up: Cook value is %f \nCOOKED: %d \nBURNT: %d"),
				//currItem->Ingredients[0]->cookedValue, currItem->Ingredients[0]->doneness == Doneness::Grilled,
				//currItem->Ingredients[0]->doneness == Doneness::Burnt));
			Player->PickUpCarryable(currItem);
			currItem = nullptr;

		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("PLAYER item is NOT nullptr"));
		}
	}

	//set the tick interval
	if (currItem == nullptr) {
		SetActorTickEnabled(false);
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 2.5f, FColor::Green, FString::Printf(TEXT("tick enabled!")));
		SetActorTickEnabled(true);
		SetActorTickInterval(0.25f);
	}
}
void AStation::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AStation::OnPlayerOverlap(UPrimitiveComponent* comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//cast the other actor to AOvercookThymeCharacter, and if it exists, call SetOverlappingActor on it
	AOvercookThymeCharacter* player = Cast<AOvercookThymeCharacter>(OtherActor);

	if(player)
	{
		UE_LOG(LogTemp, Warning, TEXT("PLAYER IN RANGE OF STATION: %s"), *GetName());
		player->SetOverlappingActor(this);
	}
}


void AStation::OnPlayerExitTrigger(UPrimitiveComponent* comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AOvercookThymeCharacter* player = Cast<AOvercookThymeCharacter>(OtherActor);

	if (player)
	{
		UE_LOG(LogTemp, Warning, TEXT("PLAYER OUT OF RANGE OF STATION: %s"), *GetName());
		player->RemoveOverlappingActor();
	}
}

UOvercookGameInstanceSubsystem* AStation::GetCookingSubsystem()
{
	return GetGameInstance()->GetSubsystem<UOvercookGameInstanceSubsystem>();
}



