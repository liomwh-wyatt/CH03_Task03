// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugWidget.generated.h"


UCLASS()
class CH03_3_API UDebugWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY(BlueprintReadOnly, Category = "디버그정보")
	float CurrentFPS;
	
	UPROPERTY(BlueprintReadOnly, Category = "디버그정보")
	int32 TargetFPS;
	
	UFUNCTION(BlueprintCallable, Category = "디버깅")
	void ApplyFPSLimit(float SliderValue);
};
