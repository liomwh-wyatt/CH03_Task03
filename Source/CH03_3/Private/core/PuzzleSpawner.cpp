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
		
		FVector SpawnLocation = GetActorLocation() + FVector(i * SpawnOffset, 0.0f, 0.0f);
		FRotator SpawnRotation = FRotator::ZeroRotator;

		GetWorld()->SpawnActor<AActor>(SelectedClass, SpawnLocation, SpawnRotation);
	}
}

void APuzzleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

