// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DeveloperSettings.h"

#include "EliteDebuggerSettings.generated.h"

/**
 * 
 */
UCLASS(config=Game, defaultconfig)
class ELITELOGGER_API UEliteDebuggerSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, config, Category="Widgets")
	TSubclassOf<UUserWidget> DebugWidget;
};
