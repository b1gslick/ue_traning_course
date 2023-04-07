// Fill out your copyright notice in the Description page of Project Settings.

#include "baseGeometryActor.h";
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
AbaseGeometryActor::AbaseGeometryActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AbaseGeometryActor::BeginPlay()
{
    Super::BeginPlay();

    FString Name = "John Connor";

    UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name)

    int WeaponNum = 4;
    float Health = 34.55;
    bool isDead = false;

    FString WeaponNumStr = "Weapons num = " + FString::FromInt(WeaponNum);
    FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
    FString IdDeadStr = "Is dead = " + FString(isDead ? "true" : "false");

    FString Stat = FString::Printf(TEXT("\n == All Stat === \n %s \n %s \n %s"), *WeaponNumStr, *HealthStr, *IdDeadStr);
    UE_LOG(LogBaseGeometry, Display, TEXT("%s"), *Stat);

    GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name)
    // printTypes();
}

// Called every frame
void AbaseGeometryActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AbaseGeometryActor::printTypes()
{
    int WeaponNum = 4;
    int KillsNum = 7;
    float Health = 34.55;
    bool isDead = false;
    bool HasWeapon = true;

    UE_LOG(LogTemp, Display, TEXT("Weapons num: %d, kills num: %i"), WeaponNum, KillsNum);
    UE_LOG(LogTemp, Display, TEXT("Health: %f"), Health);
    UE_LOG(LogTemp, Display, TEXT("Health: %.2f"), Health);
    UE_LOG(LogTemp, Display, TEXT("isDead: %d"), isDead);
    UE_LOG(LogTemp, Display, TEXT("Hasweapon: %d"), static_cast<int>(HasWeapon));
}
