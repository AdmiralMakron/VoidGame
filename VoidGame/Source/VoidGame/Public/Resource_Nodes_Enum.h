// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EResourceNodes : uint8
{

	None UMETA(DisplayName = "None"),
	Tree UMETA(DisplayName = "Tree"),
	Rock UMETA(DisplayName = "Rock"),
	Chest UMETA(DisplayName = "Chest"),
	Ore UMETA(DisplayName = "Ore"),
	
};


/**
 * 
 */
class VOIDGAME_API Resource_Nodes_Enum
{
public:
	Resource_Nodes_Enum();
	~Resource_Nodes_Enum();
};
