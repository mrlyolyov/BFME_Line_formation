// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRTSSelectMove.h"

// Sets default values
AMyRTSSelectMove::AMyRTSSelectMove()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyRTSSelectMove::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyRTSSelectMove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyRTSSelectMove::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

