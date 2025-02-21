#include "C_ResourceNode.h"
#include "Components/SceneComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BillboardComponent.h"

// Sets default values
AC_ResourceNode::AC_ResourceNode()
{
    // Set this actor to call Tick() every frame (can be turned off for performance)
    PrimaryActorTick.bCanEverTick = true;

    // Create Root Component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    RootComponent->SetMobility(EComponentMobility::Movable);

    // Create Default Editor Icon (Billboard)
    UBillboardComponent* Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("EditorIcon"));
    Billboard->SetupAttachment(RootComponent);

    // Create Static Mesh Component
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(RootComponent);
    MeshComponent->SetMobility(EComponentMobility::Movable);

    // Default ResourceNodeType (initialized when placed in the editor)
    ResourceNodeType = EResourceNodes::None;
}

void AC_ResourceNode::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    // Log to check if this function is being called
    UE_LOG(LogTemp, Warning, TEXT("OnConstruction called for ResourceNodeType: %d"), static_cast<int32>(ResourceNodeType));

    // Update the mesh based on the current ResourceNodeType
    UpdateMesh();
}

void AC_ResourceNode::UpdateMesh() const
{
    UStaticMesh* NewMesh;
    
    // Check for the 'None' case and ensure mesh is cleared
    if (ResourceNodeType == EResourceNodes::None)
    {
        NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonProjectile.BP_FirstPersonProjectile"));  // Explicitly set to nullptr to clear the mesh
        UE_LOG(LogTemp, Warning, TEXT("ResourceNodeType is 'None', clearing mesh"));
    }
    else
    {

    
        // Select the mesh based on ResourceNodeType
        switch (ResourceNodeType)
        {
        case EResourceNodes::Tree:
            NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/World/Meshes/SM_Bad_Tree.SM_Bad_Tree"));
            break;
        case EResourceNodes::Rock:
            NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/World/Meshes/SM_Bad_Rock.SM_Bad_Rock"));
            break;
        case EResourceNodes::Chest:
            NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Weapon_Pack/Mesh/Props/Interior/SM_Barrel.SM_Barrel"));
            break;
        case EResourceNodes::Ore:
            NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/World/Meshes/SM_Bad_Ore.SM_Bad_Ore"));
            break;
        default:
            NewMesh = nullptr;
            break;
        }
    }

        MeshComponent->SetStaticMesh(NewMesh);
    
}
void AC_ResourceNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    // Only update the mesh if ResourceNodeType property is modified
    if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(AC_ResourceNode, ResourceNodeType))
    {
        UpdateMesh();
    }
}
