// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

class AShooterCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class SHOOTEROASIS_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable)
	void UpdateAnimProperties(float DeltaTime);

private:

	// Pointer to the character that owns this animation instance
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AShooterCharacter> ShooterCharacter = nullptr;

	// Pointer to the character's movement component using the animation instance
	UPROPERTY(Transient)
	TObjectPtr<UCharacterMovementComponent> MoveComp = nullptr;

	// Says if character is in the air or not - jumping, falling, etc.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	bool bIsInAir = false;

	// Says if character is accelerating (changibg speed) or not - moving forward, backward, etc.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating = false;

	// Says if character is moving or not - moving forward, backward - speed different to zero
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	bool bIsMoving = false;
	
	// The speed of the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	float Speed = 0.0f;

};
