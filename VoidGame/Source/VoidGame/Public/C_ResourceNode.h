#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resource_Nodes_Enum.h"  // Include the enum header
#include "Components/StaticMeshComponent.h"
#include "C_ResourceNode.generated.h"

UCLASS(Placeable)
class VOIDGAME_API AC_ResourceNode : public AActor
{
	GENERATED_BODY()

public:    
	// Sets default values for this actor's properties
	AC_ResourceNode();

	// Resource type for this actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	EResourceNodes ResourceNodeType;

	// Static Mesh Component to display in the editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

protected:

	// Called when the actor is placed or modified in the editor
	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void BeginPlay() override;
	
private:
	// Updates the mesh based on the ResourceNodeType
	void UpdateMesh() const;

	// Optionally: to update on property changes in the editor
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};