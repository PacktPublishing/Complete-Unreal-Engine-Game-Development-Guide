// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasteringWeapon.generated.h"

/**
 * 
 */
UCLASS()
class MASTERING_API AMasteringWeapon : public AActor
{
	GENERATED_BODY()

public:
	AMasteringWeapon();

public:
	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector GunOffset = FVector(100.0f, 0.0f, 10.0f);

	/** Projectile class to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
	TSubclassOf<class AMasteringProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;
	
	/** Our weapon skeletal mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMeshComponent* WeaponMesh;

	/** Muzzle offset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* MuzzleLocation;

public:
	/** Fire the weapon */
	void Fire(FRotator ControlRotation, class UAnimInstance* AnimInst, class UMasteringInventory* Inventory);

};
