// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectMove.h"

// Sets default values
ASelectMove::ASelectMove()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASelectMove::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASelectMove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASelectMove::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

