// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class CH03_3_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingPlatform();

protected:
	virtual void BeginPlay() override;
	
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

public:	
	virtual void Tick(float DeltaTime) override;

};
