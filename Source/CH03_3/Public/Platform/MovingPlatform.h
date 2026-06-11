// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class CH03_3_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "플렛폼셋팅")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "플렛폼셋팅")
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "플렛폼셋팅")
	FVector MoveDirection;

	FVector StartLocation;

public:	
	virtual void Tick(float DeltaTime) override;

};
