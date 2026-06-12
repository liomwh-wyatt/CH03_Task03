// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

ARotatingPlatform::ARotatingPlatform()
{
 	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	RotationSpeed = 90.0f;
	ToggleInterval = 3.0f;
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	RotationSpeed = FMath::RandRange(45.0f, 180.0f);
	if (FMath::RandBool())
	{
		RotationSpeed *= -1.0f; 
	}
	
	GetWorld()->GetTimerManager().SetTimer(
		DisappearTimerHandle,
		this,
		&ARotatingPlatform::ToggleVisibility,
		ToggleInterval,
		true
	);	
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		float DeltaRot = RotationSpeed * DeltaTime;
		FRotator NewRot = FRotator(0.0f, DeltaRot, 0.0f);
		AddActorLocalRotation(NewRot);
	}
}

void ARotatingPlatform::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(DisappearTimerHandle);

	Super::EndPlay(EndPlayReason);
}

void ARotatingPlatform::ToggleVisibility()
{
	if (StaticMeshComp)
	{
		StaticMeshComp->ToggleVisibility();
	}
}

