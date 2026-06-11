// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DebugWidget.h"
#include "Kismet/KismetSystemLibrary.h"

void UDebugWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TargetFPS = 120;
	CurrentFPS = 0.0f;
}

void UDebugWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (InDeltaTime > 0.0f)
	{
		CurrentFPS = 1.0f / InDeltaTime;
	}
}

void UDebugWidget::ApplyFPSLimit(float SliderValue)
{
	TargetFPS = FMath::Clamp(FMath::RoundToInt(SliderValue * 110.0f) + 10, 10, 120);

	FString Command = FString::Printf(TEXT("t.MaxFPS %d"), TargetFPS);

	UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), Command);
}
