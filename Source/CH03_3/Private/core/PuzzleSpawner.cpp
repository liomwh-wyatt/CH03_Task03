// Fill out your copyright notice in the Description page of Project Settings.


#include "core/PuzzleSpawner.h"
#include "Engine/World.h"

APuzzleSpawner::APuzzleSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpawnCount = 5;
	SpawnOffset = 300.0f;
}

void APuzzleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	if (ObstacleClassesToSpawn.IsEmpty())
	{
		return;
	}
	
	for (int32 i = 0; i < SpawnCount; ++i)
	{
		int32 RandomIndex = FMath::RandRange(0, ObstacleClassesToSpawn.Num() - 1);
        
		TSubclassOf<AActor> SelectedClass = ObstacleClassesToSpawn[RandomIndex];

		if (SelectedClass == nullptr)
		{
			continue;
		}
		
		float RandomY = FMath::RandRange(-400.0f, 400.0f); // 좌우 -400 ~ 400 범위
		float RandomZ = FMath::RandRange(0.0f, 200.0f);		
		FVector SpawnLocation = GetActorLocation() + FVector(i * SpawnOffset, RandomY, RandomZ);
        
		float RandomYaw = FMath::RandRange(0.0f, 360.0f);
		FRotator SpawnRotation = FRotator(0.0f, RandomYaw, 0.0f);

		GetWorld()->SpawnActor<AActor>(SelectedClass, SpawnLocation, SpawnRotation);
	}
}

void APuzzleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

