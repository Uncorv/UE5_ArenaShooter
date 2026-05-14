#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;

UCLASS()
class UE5_ARENASHOOTER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float Value);
	void MoveForward(float Value);
	void TurnRight(float Value);
	void TurnUp(float Value);

	void SetMovementSpeed(float Speed);

	void DoSprint();
	void StopSprint();
	void ToggleCrouch();


private:
	
	UPROPERTY(EditAnywhere)
	UCameraComponent *Camera = nullptr;
	UPROPERTY(EditAnywhere, Category = "MovementSpeed")
	float MovementSpeed = 500.f;
	UPROPERTY(EditAnywhere, Category = "MovementSpeed")
	float SprintSpeed = 1000.f;
	UPROPERTY(EditAnywhere, Category = "MovementSpeed")
	float CrouchSpeed = 250.f;

};
