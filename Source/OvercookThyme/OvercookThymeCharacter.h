// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OvercookThymeCharacter.generated.h"

UCLASS(Blueprintable)
class AOvercookThymeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AOvercookThymeCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/** Returns TopDownCameraComponent subobject **/
	//FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	//FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	//FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }


	AActor* overlappedStation;

	UFUNCTION(BlueprintCallable)
	void SetOverlappingActor(AActor* overlap);

	UFUNCTION(BlueprintCallable)
	void RemoveOverlappingActor();

	UFUNCTION(BlueprintCallable)
	void InteractEvent();


private:
	/** Top down camera */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	//class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;
};

