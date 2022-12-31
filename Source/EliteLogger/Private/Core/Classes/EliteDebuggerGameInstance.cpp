// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Classes/EliteDebuggerGameInstance.h"

#include "Blueprint/UserWidget.h"


void UEliteDebuggerGameInstance::ShowEliteDebugWidget()
{
#if !UE_BUILD_SHIPPING

	if (SpawnedWidget == nullptr && DebugWidget != nullptr)
	{
		SpawnedWidget = CreateWidget<UUserWidget>(GetWorld(), DebugWidget);
		SpawnedWidget->AddToViewport();
	}
	else
	{
		if (SpawnedWidget != nullptr && SpawnedWidget->IsVisible())
		{
			SpawnedWidget->RemoveFromParent();
			SpawnedWidget = nullptr;
		}
	}
#endif
}
