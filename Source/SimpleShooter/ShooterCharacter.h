// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//Dont expect anything to change so make it const
	UFUNCTION(BlueprintPure)
	bool IsDead() const; 

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const; 
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Override the TakeDamage
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);

	void Shoot();


private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void LookRight(float AxisValue);


	UPROPERTY(EditAnywhere)
	float RotationRate = 10.f;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere)
	float Health;


};
