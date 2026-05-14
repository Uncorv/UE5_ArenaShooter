#include "Characters/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(GetRootComponent());
	Camera->bUsePawnControlRotation = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
	GetCharacterMovement()->MaxWalkSpeedCrouched = CrouchSpeed;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("TurnRight", this, &APlayerCharacter::TurnRight);
	PlayerInputComponent->BindAxis("TurnUp", this, &APlayerCharacter::TurnUp);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::DoSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerCharacter::StopSprint);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::ToggleCrouch);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
}

void APlayerCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void APlayerCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void APlayerCharacter::TurnRight(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::TurnUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::SetMovementSpeed(float Speed)
{
	GetCharacterMovement()->MaxWalkSpeed = Speed;
}

void APlayerCharacter::DoSprint()
{
	SetMovementSpeed(SprintSpeed);
}

void APlayerCharacter::StopSprint()
{
	SetMovementSpeed(MovementSpeed);
}

void APlayerCharacter::ToggleCrouch()
{
	if (!bIsCrouched)
	{
		Crouch();
	}
	else
	{
		UnCrouch();
	}
}