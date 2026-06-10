// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/RotatingPlatform.h"
#include "Components/StaticMeshComponent.h"

ARotatingPlatform::ARotatingPlatform()
{
 	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// 2. Static Mesh Component 생성 및 SceneRoot에 부착(Attach)
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

