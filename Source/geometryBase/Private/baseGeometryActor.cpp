// Fill out your copyright notice in the Description page of Project Settings.

#include "baseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
AbaseGeometryActor::AbaseGeometryActor()
{
    // Set this actor to call Tick() every frame.
    // You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AbaseGeometryActor::BeginPlay()
{
    Super::BeginPlay();

    BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
    SetRootComponent(BaseMesh);

    // printStringTypes();
    // printTypes();
}

// Called every frame
void AbaseGeometryActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
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

    GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stat, true, FVector2D(1.5));
}