// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DebugSubsystem.generated.h"


USTRUCT(BlueprintType)
struct FTrackedPackage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Tracked Variables")
	TMap<FName, float> TrackedVariables_Float;

	UPROPERTY(BlueprintReadOnly, Category="Tracked Variables")
	TMap<FName, int32> TrackedVariables_INT32;

	UPROPERTY(BlueprintReadOnly, Category="Tracked Variables")
	TMap<FName, bool> TrackedVariables_Boolean;

	UPROPERTY(BlueprintReadOnly, Category="Tracked Variables")
	TMap<FName, UObject*> TrackedVariables_Object;

	UPROPERTY(BlueprintReadOnly, Category="Tracked Variables")
	TMap<FName, FVector> TrackedVariables_FVector;
	
};
/**
 * 
 */
UCLASS(Blueprintable)
class ELITELOGGER_API UDebugSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintPure, Category="Elite Logger")
	FTrackedPackage GetTrackedVariablesList(const UObject* Object);

	UFUNCTION(BlueprintCallable,meta = (DisplayName = "Track A Boolean", DevelopmentOnly), Category="Elite Logger")
	void TrackABoolean(UObject* ObjectToTrack, const FName VariableName, const bool Value);
	
	UFUNCTION(BlueprintCallable,meta = (DisplayName = "Track An Integer", DevelopmentOnly), Category="Elite Logger")
	void TrackAnInteger(UObject* ObjectToTrack, const FName VariableName, const int32 Value);

	UFUNCTION(BlueprintCallable,meta = (DisplayName = "Track A Float", DevelopmentOnly), Category="Elite Logger")
	void TrackAFloat(UObject* ObjectToTrack, const FName VariableName, const float Value);

	UFUNCTION(BlueprintCallable,meta = (DisplayName = "Track A Vector", DevelopmentOnly), Category="Elite Logger")
	void TrackAVector(UObject* ObjectToTrack, const FName VariableName, const FVector Value);

	UFUNCTION(BlueprintCallable,meta = (DisplayName = "Track An Object", DevelopmentOnly), Category="Elite Logger")
	void TrackAnObject(UObject* ObjectToTrack, const FName VariableName, UObject* Value);

	// Internal Setters For Blueprint Node call these directly in C++
	UFUNCTION(meta=(DevelopmentOnly))
	void AddTrackedVariable_Bool(UObject* Target, const FName& VariableName, const bool Value);

	UFUNCTION(meta=(DevelopmentOnly))
	void AddTrackedVariable_INT32(UObject* Target, const FName& VariableName, const int32 Value);

	UFUNCTION(meta=(DevelopmentOnly))
	void AddTrackedVariable_Float(UObject* Target, const FName& VariableName, const float Value);

	UFUNCTION(meta=(DevelopmentOnly))
	void AddTrackedVariable_FVector(UObject* Target, const FName& VariableName, const FVector Value);

	UFUNCTION(meta=(DevelopmentOnly))
	void AddTrackedVariable_Object(UObject* Target, const FName& VariableName, UObject* Value);

	void ShowEliteDebugWidget();

private:
	UPROPERTY()
	TMap<TObjectPtr<UObject>, FTrackedPackage> TrackedVariables;

	UPROPERTY()
	TObjectPtr<UUserWidget> SpawnedWidget;

	IConsoleObject* ShowDebugWidgetCommand = nullptr;
};
