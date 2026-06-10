// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

ARotatingPlatform::ARotatingPlatform()
{
 	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	RotationSpeed = 90.0f;
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
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

