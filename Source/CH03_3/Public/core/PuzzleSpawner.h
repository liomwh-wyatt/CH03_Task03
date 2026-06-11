// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzleSpawner.generated.h"

UCLASS()
class CH03_3_API APuzzleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	APuzzleSpawner();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,Category = "스폰셋팅")
	TArray<TSubclassOf<AActor>> ObstacleClassesToSpawn;
	
	UPROPERTY(EditAnywhere,Category = "스폰셋팅")
	int32 SpawnCount;
	
	UPROPERTY(EditAnywhere,Category = "스폰셋팅")
	float SpawnOffset;

public:	
	virtual void Tick(float DeltaTime) override;

};
