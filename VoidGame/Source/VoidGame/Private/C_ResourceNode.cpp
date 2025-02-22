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
    int32 MeshType = 0;
    
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
        case EResourceNodes::Tree: //MeshType 1
            NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/World/Meshes/PlaceholderMeshes_New/Tree1_PlaceholderExport.Tree1_PlaceholderExport"));
            MeshType = 1;
            break;
        case EResourceNodes::Rock: //MeshType 2
            NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/World/Meshes/PlaceholderMeshes_New/HarvestableRock1_PlaceholderExport.HarvestableRock1_PlaceholderExport"));
            MeshType = 2;
            break;
        case EResourceNodes::Chest: //MeshType 3
            NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Weapon_Pack/Mesh/Props/Interior/SM_Barrel.SM_Barrel"));
            MeshType = 3;
            break;
        case EResourceNodes::Ore: //MeshType 4
            NewMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/World/Meshes/PlaceholderMeshes_New/OreRock_PlaceholderExport.OreRock_PlaceholderExport"));
            MeshType = 4;
            break;
        default:
            NewMesh = nullptr; //MeshType 0
            MeshType = 0;
            break;
        }
    }

        MeshComponent->SetStaticMesh(NewMesh);
        MeshComponent->SetWorldScale3D(FVector(0.2, 0.2, 0.2));

    //Sets static mesh scale appropriately. In the future, make sure exported (.fbx files) are scaled correctly.

    if (MeshType == 1)
    {
        MeshComponent->SetWorldScale3D(FVector(0.1, 0.1, 0.1));
    }
    else if (MeshType == 2)
    {
        MeshComponent->SetWorldScale3D(FVector(0.4, 0.4, 0.4));
    }
        
    else if (MeshType == 3)
    {
        MeshComponent->SetWorldScale3D(FVector(1, 1, 1));
    }

    else if (MeshType == 4)
    {
        MeshComponent->SetWorldScale3D(FVector(0.4, 0.4, 0.4));
    }
        
    else
    {
        MeshComponent->SetWorldScale3D(FVector(1, 1, 1));
    }
    
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
