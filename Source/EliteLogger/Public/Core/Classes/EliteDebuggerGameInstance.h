// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EliteDebuggerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ELITELOGGER_API UEliteDebuggerGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Widgets")
	TSubclassOf<UUserWidget> DebugWidget;

public:
	UFUNCTION(Exec, Category="Elite Logger")
	void ShowEliteDebugWidget();


private:
	UPROPERTY()
	TObjectPtr<UUserWidget> SpawnedWidget;
	
};
