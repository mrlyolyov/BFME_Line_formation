

#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "MyRTSHUD.h"
#include "MyActor.h"
#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"
#include "GameFramework/PlayerController.h"
#include "MyRTSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RTSBFME_API AMyRTSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	AMyRTSPlayerController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	AMyRTSHUD* Hud;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<class AActor> toSpawn;

	//void Spawn();

protected:

	UFUNCTION()
	void SelectionPressed();
	
	UFUNCTION()
	void SelectionReleased();

	UFUNCTION()
	void MoveReleased();

	UPROPERTY()
	TArray<ARTSbfmeCharacter*> SelectedActors;

	UPROPERTY()
	TArray<ADecalActor*> decals; 

	UPROPERTY()
		TArray<FVector> locations;

	UFUNCTION(BlueprintCallable)
	void Test();

	UFUNCTION(BlueprintCallable)
	void TestTwo();

	UFUNCTION(BlueprintCallable)
	void TestT();

	UFUNCTION(BlueprintCallable)
	void SpawnArrow();

	UFUNCTION(BlueprintCallable)
	void EnableFormation();

	UPROPERTY()
	bool isFormationSet = false;

	UPROPERTY()
	FHitResult Result;

	UPROPERTY()
	ADecalActor* decalArrow;

	UPROPERTY()
	ADecalActor* decalUnit;

	bool activateLeft = false;

	bool activateRight = false;

	
};
