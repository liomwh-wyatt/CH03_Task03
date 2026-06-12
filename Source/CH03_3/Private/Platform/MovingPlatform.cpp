// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/MovingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	MoveSpeed = 300.0f;
	MaxRange = 800.0f;
	MoveDirection = FVector(1.0f, 0.0f, 0.0f);

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	MoveDirection.Normalize();
	
	MoveSpeed = FMath::RandRange(100.0f, 500.0f);
	MaxRange = FMath::RandRange(300.0f, 800.0f);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector CurrentLoc = GetActorLocation();
	
	CurrentLoc += MoveDirection * MoveSpeed * DeltaTime;
	
	SetActorLocation(CurrentLoc);
	
	float DisMoved = FVector::Dist(StartLocation, CurrentLoc);
	if (DisMoved >= MaxRange)
	{
		MoveDirection *= -1;
		SetActorLocation(StartLocation + (MoveDirection * -1 * MaxRange));
	}
}

