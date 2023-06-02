// Fill out your copyright notice in the Description page of Project Settings.

#include "baseGeometryActor.h"
#include "Engine/Engine.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
AbaseGeometryActor::AbaseGeometryActor()
{
    // Set this actor to call Tick() every frame.
    // You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
    SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void AbaseGeometryActor::BeginPlay()
{
    Super::BeginPlay();

    InitialLocation = GetActorLocation();

    // printTransform();
    // printStringTypes();
    // printTypes();
    SetColor(GeometryData.Color);

    GetWorldTimerManager().SetTimer(TimerHandle, this, &AbaseGeometryActor::OnTimerFired, GeometryData.TimerRate, true);
}

void AbaseGeometryActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    UE_LOG(LogBaseGeometry, Error, TEXT("Actor is dead: %s"), *GetName());
    Super::EndPlay(EndPlayReason);
}

// Called every frame
void AbaseGeometryActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    HandleMovement();
}

void AbaseGeometryActor::HandleMovement()
{
    switch (GeometryData.MoveType)
    {
        case EMovementType::Sin:
        {
            FVector CurrentLocation = GetActorLocation();
            if (GetWorld())
            {

                float Time = GetWorld()->GetTimeSeconds();
                CurrentLocation.Z = InitialLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency * Time);

                SetActorLocation(CurrentLocation);
            }
        }
        break;
        case EMovementType::Static: break;
        default: break;
    }
}

void AbaseGeometryActor::printTypes()
{
    UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name: %s"), *GetName());
    UE_LOG(LogBaseGeometry, Warning, TEXT("Weapons num: %d, kills num: %i"), WeaponNum, KillsNum);
    UE_LOG(LogBaseGeometry, Warning, TEXT("Health: %f"), Health);
    UE_LOG(LogBaseGeometry, Warning, TEXT("isDead: %d"), isDead);
    UE_LOG(LogBaseGeometry, Warning, TEXT("Hasweapon: %d"), static_cast<int>(HasWeapon));
}

void AbaseGeometryActor::printStringTypes()
{
    FString Name = "John Connor";

    UE_LOG(LogBaseGeometry, Warning, TEXT("Name: %s"), *Name)

    FString WeaponNumStr = "Weapons num = " + FString::FromInt(WeaponNum);
    FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
    FString IdDeadStr = "Is dead = " + FString(isDead ? "true" : "false");

    FString Stat = FString::Printf(TEXT("\n == All Stat === \n %s \n %s \n %s"), *WeaponNumStr, *HealthStr, *IdDeadStr);
    UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *Stat);

    if (GEngine)
    {

        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stat, true, FVector2D(1.5));
    }
}

void AbaseGeometryActor::printTransform()
{
    FTransform Transform = GetActorTransform();
    FVector Location = Transform.GetLocation();
    FRotator Rotator = Transform.Rotator();
    FVector Scale = Transform.GetScale3D();
    UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name: %s"), *GetName());
    UE_LOG(LogBaseGeometry, Warning, TEXT("Transform: %s"), *Transform.ToString());
    UE_LOG(LogBaseGeometry, Warning, TEXT("Location: %s"), *Location.ToString());
    UE_LOG(LogBaseGeometry, Warning, TEXT("Rotator: %s"), *Rotator.ToString());
    UE_LOG(LogBaseGeometry, Warning, TEXT("Scale: %s"), *Scale.ToString());

    UE_LOG(LogBaseGeometry, Error, TEXT("Transform: %s"), *Transform.ToHumanReadableString());
}

void AbaseGeometryActor::SetColor(const FLinearColor& Color)
{
    if (!BaseMesh) return;
    UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0);
    if (DynMaterial)
    {
        DynMaterial->SetVectorParameterValue("Color", Color);
    }
}

void AbaseGeometryActor::OnTimerFired()
{
    if (++TimerCount <= MaxTimerCount)
    {

        const FLinearColor NewColor = FLinearColor::MakeRandomColor();
        UE_LOG(LogBaseGeometry, Display, TEXT("Timer Count: %i, Color to set up: %s"), TimerCount, *NewColor.ToString());
        SetColor(NewColor);
        OnColorChanged.Broadcast(NewColor, GetName());
    }
    else
    {
        UE_LOG(LogBaseGeometry, Warning, TEXT("Timer Stopped"));
        GetWorldTimerManager().ClearTimer(TimerHandle);
        OnTimerFinished.Broadcast(this);
    }
}
