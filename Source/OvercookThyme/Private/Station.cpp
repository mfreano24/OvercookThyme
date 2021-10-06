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
	UE_LOG(LogTemp, Warning, TEXT("STATION INTERACTED WITH: %s"), *GetName());
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



