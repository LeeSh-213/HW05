// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HW.generated.h"

UCLASS()
class HW05_API AHW : public AActor
{
	GENERATED_BODY()
	
public:	
	AHW();
protected:
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsMovable(const FVector2D& Current, const FVector2D& Target) const;

	void TrySpawnActor(const FVector& Location);
	
private:
	int32 Step() const;
	void Move();
};
