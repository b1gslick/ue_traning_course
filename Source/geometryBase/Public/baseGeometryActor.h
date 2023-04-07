// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "baseGeometryActor.generated.h"

UCLASS()
class GEOMETRYBASE_API AbaseGeometryActor : public AActor
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AbaseGeometryActor();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

private:
  void printTypes();
};
