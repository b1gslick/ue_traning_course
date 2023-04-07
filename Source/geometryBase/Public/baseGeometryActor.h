// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "baseGeometryActor.generated.h"

UCLASS()
class GEOMETRYBASE_API AbaseGeometryActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AbaseGeometryActor();

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BaseMesh;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Weapon")
    int32 WeaponNum = 4;

    UPROPERTY(EditDefaultsOnly, Category = "Stat")
    int32 KillsNum = 7;

    UPROPERTY(EditInstanceOnly, Category = "Health")
    float Health = 34.55;

    UPROPERTY(EditAnywhere, Category = "Health")
    bool isDead = false;

    UPROPERTY(VisibleAnywhere, Category = "Weapon")
    bool HasWeapon = true;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    void printTypes();
    void printStringTypes();
};
