// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Subsystems/DebugSubsystem.h"

void UDebugSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}


FTrackedPackage UDebugSubsystem::GetTrackedVariablesList(const UObject* Object)
{
	return TrackedVariables.FindRef(Object);
}

void UDebugSubsystem::TrackABoolean(UObject* ObjectToTrack, const FName VariableName, const bool Value)
{
	AddTrackedVariable_Bool(ObjectToTrack, VariableName, Value);
}

void UDebugSubsystem::TrackAnInteger(UObject* ObjectToTrack, const FName VariableName, const int32 Value)
{
	AddTrackedVariable_INT32(ObjectToTrack, VariableName, Value);
}

void UDebugSubsystem::TrackAFloat(UObject* ObjectToTrack, const FName VariableName, const float Value)
{
	AddTrackedVariable_Float(ObjectToTrack, VariableName, Value);
}

void UDebugSubsystem::TrackAVector(UObject* ObjectToTrack, const FName VariableName, const FVector Value)
{
	AddTrackedVariable_FVector(ObjectToTrack, VariableName, Value);
}

void UDebugSubsystem::TrackAnObject(UObject* ObjectToTrack, const FName VariableName, UObject* Value)
{
	AddTrackedVariable_Object(ObjectToTrack, VariableName, Value);
}


void UDebugSubsystem::AddTrackedVariable_Bool(UObject* Target, const FName& VariableName, const bool Value)
{
	// If Package Is Found Update it else create one
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)

	FTrackedPackage NewPackage;
	if (TrackedVariables.Find(Target))
	{
		NewPackage = TrackedVariables.FindRef(Target);

		NewPackage.TrackedVariables_Boolean.Add(VariableName, Value);
		
		TrackedVariables.Add(Target, NewPackage);
		
	}
	else
	{
		NewPackage.TrackedVariables_Boolean.Add(VariableName, Value);
		TrackedVariables.Add(Target, NewPackage);
	}

#endif
	
	
}

void UDebugSubsystem::AddTrackedVariable_INT32(UObject* Target, const FName& VariableName, const int32 Value)
{

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	FTrackedPackage NewPackage;
	if (TrackedVariables.Find(Target))
	{
		NewPackage = TrackedVariables.FindRef(Target);

		NewPackage.TrackedVariables_INT32.Add(VariableName, Value);
		
		TrackedVariables.Add(Target, NewPackage);
		
	}
	else
	{
		NewPackage.TrackedVariables_INT32.Add(VariableName, Value);
		TrackedVariables.Add(Target, NewPackage);
	}
#endif
	
}

void UDebugSubsystem::AddTrackedVariable_Float(UObject* Target, const FName& VariableName, const float Value)
{

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	FTrackedPackage NewPackage;
	if (TrackedVariables.Find(Target))
	{
		NewPackage = TrackedVariables.FindRef(Target);

		NewPackage.TrackedVariables_Float.Add(VariableName, Value);
		
		TrackedVariables.Add(Target, NewPackage);
		
	}
	else
	{
		NewPackage.TrackedVariables_Float.Add(VariableName, Value);
		TrackedVariables.Add(Target, NewPackage);
	}
#endif
	
}

void UDebugSubsystem::AddTrackedVariable_FVector(UObject* Target, const FName& VariableName, const FVector Value)
{

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	FTrackedPackage NewPackage;
	if (TrackedVariables.Find(Target))
	{
		NewPackage = TrackedVariables.FindRef(Target);

		NewPackage.TrackedVariables_FVector.Add(VariableName, Value);
		
		TrackedVariables.Add(Target, NewPackage);
		
	}
	else
	{
		NewPackage.TrackedVariables_FVector.Add(VariableName, Value);
		TrackedVariables.Add(Target, NewPackage);
	}
#endif
	
}

void UDebugSubsystem::AddTrackedVariable_Object(UObject* Target, const FName& VariableName, UObject* Value)
{

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	FTrackedPackage NewPackage;
	if (TrackedVariables.Find(Target))
	{
		NewPackage = TrackedVariables.FindRef(Target);

		NewPackage.TrackedVariables_Object.Add(VariableName, Value);
		
		TrackedVariables.Add(Target, NewPackage);
		
	}
	else
	{
		NewPackage.TrackedVariables_Object.Add(VariableName, Value);
		TrackedVariables.Add(Target, NewPackage);
	}
#endif
	
}



