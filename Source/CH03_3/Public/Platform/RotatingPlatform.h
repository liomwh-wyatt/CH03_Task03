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
	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "플렛폼셋팅")
	float RotationSpeed;

	FTimerHandle DisappearTimerHandle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "플렛폼셋팅")
	float ToggleInterval;
	
	void ToggleVisibility();
	
public:	
	virtual void Tick(float DeltaTime) override;

};
