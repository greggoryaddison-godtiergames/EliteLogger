// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Libraries/EliteDebuggerLibrary.h"

#include "Core/Subsystems/DebugSubsystem.h"
#include "UObject/UnrealTypePrivate.h"

bool UEliteDebuggerLibrary::SetFloatByName(UObject * Target, FName VarName, float NewValue, float & OutValue)
{
	if (Target)
	{
		if (FFloatProperty* ValueProp = FindFProperty<FFloatProperty>(*VarName.ToString()))
		{

			UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
			if (!DebugSubsystem) { return false; }

			// Add the newly tracked variable into our map.
			DebugSubsystem->AddTrackedVariable_Float(Target, VarName, NewValue);
			
			// ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			// const float FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			// OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetIntByName(UObject * Target, FName VarName, int NewValue, int & OutValue)
{
	if (Target)
	{
		if (FIntProperty* ValueProp = FindFProperty<FIntProperty>(*VarName.ToString()))
		{

			UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
			if (!DebugSubsystem) { return false; }

			// Add the newly tracked variable into our map.
			DebugSubsystem->AddTrackedVariable_INT32(Target, VarName, NewValue);
			
			// ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			// const int FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			// OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetInt64ByName(UObject * Target, FName VarName, int64 NewValue, int64 & OutValue)
{
	//possibly not working
	if (Target)
	{
		if (const FInt64Property* ValueProp = FindFProperty<FInt64Property>(*VarName.ToString()))
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			const int64 FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetFVectorByName(UObject* Target, FName VarName, FVector NewValue, FVector& OutValue)
{
	if (Target)
	{

		UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
		if (!DebugSubsystem) { return false; }

		// Add the newly tracked variable into our map.
		DebugSubsystem->AddTrackedVariable_FVector(Target, VarName, NewValue);
			
		
			// ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			// const int64 FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			// OutValue = FoundValue;
			return true;
	
	}
	return false;
}

bool UEliteDebuggerLibrary::SetBoolByName(UObject * Target, FName VarName, bool NewValue, bool & OutValue)
{
	if (Target)
	{
		if (FBoolProperty* ValueProp = FindFProperty<FBoolProperty>(*VarName.ToString()))
		{
			UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
			if (!DebugSubsystem) { return false; }

			// Add the newly tracked variable into our map.
			DebugSubsystem->AddTrackedVariable_Bool(Target, VarName, NewValue);

			
			// ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			// const bool FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			// OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetNameByName(UObject * Target, FName VarName, FName NewValue, FName & OutValue)
{
	if (Target)
	{
		if (const FNameProperty* ValueProp = FindFProperty<FNameProperty>(*VarName.ToString()))
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			const FName FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetObjectByName(UObject * Target, FName VarName, UObject* NewValue, UObject* & OutValue)
{
	if (Target)
	{
		UObject* FoundValue = nullptr;
		if (FObjectProperty* ValueProp = FindFProperty<FObjectProperty>(*VarName.ToString()))
		{

			UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
			if (!DebugSubsystem) { return false; }

			// Add the newly tracked variable into our map.
			DebugSubsystem->AddTrackedVariable_Object(Target, VarName, NewValue);
			
			// ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			// FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			// OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetClassByName(UObject * Target, FName VarName, class UClass* NewValue, class UClass* & OutValue)
{
	//Probably some weirdness to do here
	/*
	if (Target)
	{
		class UClass FoundValue;
		UClassProperty* ValueProp = FindField<UClassProperty>(Target->GetClass(), VarName);
		if (ValueProp)
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	*/
	return false;
}

bool UEliteDebuggerLibrary::SetByteByName(UObject * Target, FName VarName, uint8 NewValue, uint8 & OutValue)
{
	if (Target)
	{
		if (const FByteProperty* ValueProp = FindFProperty<FByteProperty>(*VarName.ToString()))
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			const uint8 FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetStringByName(UObject * Target, FName VarName, FString NewValue, FString & OutValue)
{
	if (Target)
	{
		if (const FStrProperty* ValueProp = FindFProperty<FStrProperty>(*VarName.ToString()))
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			FString FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetTextByName(UObject * Target, FName VarName, FText NewValue, FText & OutValue)
{
	if (Target)
	{
		if (const FTextProperty* ValueProp = FindFProperty<FTextProperty>(*VarName.ToString()))
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			const FText FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	return false;
}

bool UEliteDebuggerLibrary::SetStructByName(UObject * Target, FName VarName, UScriptStruct* NewValue, UScriptStruct* & OutValue)
{
	//This will need to iterate and shit
	/*
	if (Target)
	{
		UScriptStruct* FoundValue;
		UStructProperty* ValueProp = FindField<UStructProperty>(Target->GetClass(), VarName);
		if (ValueProp)
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	*/
	return false;
}

bool UEliteDebuggerLibrary::SetEnumByName(UObject * Target, FName VarName, uint8 NewValue, uint8 & OutValue)
{
	//Some kind of magic here i guess
	/*
	if (Target)
	{
		uint8 FoundValue;
		UEnumProperty* ValueProp = FindField<UEnumProperty>(Target->GetClass(), VarName);
		if (ValueProp)
		{
			ValueProp->SetPropertyValue_InContainer(Target, NewValue); //this actually sets the variable
			FoundValue = ValueProp->GetPropertyValue_InContainer(Target);
			OutValue = FoundValue;
			return true;
		}
	}
	*/
	return false;
}

//Getters

bool UEliteDebuggerLibrary::GetFloatByName(UObject * Target, FName VarName, float & OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
		if (!DebugSubsystem) { return false; }

		// Add the newly tracked variable into our map.
		const auto FoundPackage = DebugSubsystem->GetTrackedVariablesList(Target);

		OutValue = FoundPackage.TrackedVariables_Float.FindRef(VarName);
		return true;
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetFVectorByName(UObject* Target, FName VarName, FVector& OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
		{
		UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
		if (!DebugSubsystem) { return false; }

		// Add the newly tracked variable into our map.
		const auto FoundPackage = DebugSubsystem->GetTrackedVariablesList(Target);

		OutValue = FoundPackage.TrackedVariables_FVector.FindRef(VarName);
		return true;
		}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetIntByName(UObject * Target, FName VarName, int & OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
		if (!DebugSubsystem) { return false; }

		// Add the newly tracked variable into our map.
		const auto FoundPackage = DebugSubsystem->GetTrackedVariablesList(Target);

		OutValue = FoundPackage.TrackedVariables_INT32.FindRef(VarName);
		return true;
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetInt64ByName(UObject * Target, FName VarName, int64 & OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		if (const FInt64Property* ValueProp = FindFProperty<FInt64Property>(*VarName.ToString())) //if we found variable
		{
			const int64 FoundValue = ValueProp->GetPropertyValue_InContainer(Target);  // get the value from FloatProp
			OutValue = FoundValue;  // return float
			return true; // we can return
		}
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetBoolByName(UObject * Target, FName VarName, bool &OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
		if (!DebugSubsystem) { return false; }

		// Add the newly tracked variable into our map.
		const auto FoundPackage = DebugSubsystem->GetTrackedVariablesList(Target);

		OutValue = FoundPackage.TrackedVariables_Boolean.FindRef(VarName);
		return true;
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetNameByName(UObject * Target, FName VarName, FName & OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		if (const FNameProperty* ValueProp = FindFProperty<FNameProperty>(*VarName.ToString())) //if we found variable
		{
			const FName FoundValue = ValueProp->GetPropertyValue_InContainer(Target);  // get the value from FloatProp
			OutValue = FoundValue;  // return float
			return true; // we can return
		}
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetObjectByName(UObject * Target, FName VarName, UObject *& OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		UDebugSubsystem* DebugSubsystem = Target->GetWorld()->GetGameInstance()->GetSubsystem<UDebugSubsystem>();
		if (!DebugSubsystem) { return false; }

		// Add the newly tracked variable into our map.
		const auto FoundPackage = DebugSubsystem->GetTrackedVariablesList(Target);

		OutValue = FoundPackage.TrackedVariables_Object.FindRef(VarName);
		return true;
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetClassByName(UObject * Target, FName VarName, UClass *& OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		if (const FClassProperty* ValueProp = FindFProperty<FClassProperty>(*VarName.ToString())) //if we found variable
		{
			UClass* FoundValue = ValueProp->GetPropertyValue_InContainer(Target)->StaticClass();  // get the value from FloatProp
			OutValue = FoundValue;  // return float
			return true; // we can return
		}
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetByteByName(UObject * Target, FName VarName, uint8 & OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		if (const FInt8Property* ValueProp = FindFProperty<FInt8Property>(*VarName.ToString())) //if we found variable
		{
			const uint8 FoundValue = ValueProp->GetPropertyValue_InContainer(Target);  // get the value from FloatProp
			OutValue = FoundValue;  // return float
			return true; // we can return
		}
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetStringByName(UObject * Target, FName VarName, FString & OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		if (const FStrProperty* ValueProp = FindFProperty<FStrProperty>(*VarName.ToString())) //if we found variable
		{
			FString FoundValue = ValueProp->GetPropertyValue_InContainer(Target);  // get the value from FloatProp
			OutValue = FoundValue;  // return float
			return true; // we can return
		}
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetTextByName(UObject * Target, FName VarName, FText & OutValue)
{
	if (Target) //make sure Target was set in blueprints. 
	{
		if (const FTextProperty* ValueProp = FindFProperty<FTextProperty>(*VarName.ToString())) //if we found variable
		{
			const FText FoundValue = ValueProp->GetPropertyValue_InContainer(Target);  // get the value from FloatProp
			OutValue = FoundValue;  // return float
			return true; // we can return
		}
	}
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetStructByName(UObject * Target, FName VarName, UScriptStruct *& OutValue)
{
	/*
	if (Target) //make sure Target was set in blueprints. 
	{
		UScriptStruct* FoundValue;
		UStructProperty* ValueProp = FindField<UStructProperty>(Target->GetClass(), VarName);  // try to find float property in Target named VarName
		if (ValueProp) //if we found variable
		{
			FoundValue = ValueProp->GetPropertyValue_InContainer(Target);  // get the value from FloatProp
			OutValue = FoundValue;  // return float
			return true; // we can return
		}
	}
	*/
	return false; // we haven't found variable return false
}

bool UEliteDebuggerLibrary::GetEnumByName(UObject * Target, FName VarName, uint8 & OutValue)
{
	/*
	if (Target) //make sure Target was set in blueprints. 
	{
		float FoundValue;
		UEnumProperty* ValueProp = FindField<UEnumProperty>(Target->GetClass(), VarName);  // try to find float property in Target named VarName
		if (ValueProp) //if we found variable
		{
			FoundValue = ValueProp->GetPropertyValue_InContainer(Target);  // get the value from FloatProp
			OutValue = FoundValue;  // return float
			return true; // we can return
		}
	}
	*/
	return false; // we haven't found variable return false
}