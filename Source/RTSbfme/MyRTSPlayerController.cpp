#include "MyRTSPlayerController.h"
#include <Runtime\AIModule\Classes\Blueprint\AIBlueprintHelperLibrary.h>
#include "UObject/ConstructorHelpers.h"
#include "MyRTSPlayerController.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>
#include <Runtime\Engine\Classes\Kismet\KismetMathLibrary.h>


AMyRTSPlayerController::AMyRTSPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AMyRTSPlayerController::BeginPlay()
{
	//marin
	Hud = Cast<AMyRTSHUD>(GetHUD());
}

void AMyRTSPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (activateLeft && activateRight && SelectedActors.Num()>0)
	{
	//	UE_LOG(LogTemp, Warning, TEXT("Marin"));
		//activateLeft = false;
		//activateRight = false;
	//	TestT();
	//	
	//	UMaterial* Material = LoadObject<UMaterial>(NULL, TEXT("Material'/Game/TopDownCPP/Blueprints/Arrow.Arrow'"));
	//	FHitResult Result;
	//	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, Result);
	//	decal = GetWorld()->SpawnActor<ADecalActor>(Result.Location, FRotator());
	//	
		if (decalArrow)
		{
	//		decal->SetDecalMaterial(Material);
			//decal->SetLifeSpan(4.0f);
	//		decal->GetDecal()->DecalSize = FVector(32.0f, 64.0f, 64.0f);
			//m_previousActionDecal = decal;
	//	}
	//	else
		//	FHitResult	Result;
			GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, Result);
			FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(decalArrow->GetActorLocation(), Result.Location);
			FRotator h;
			//P//layerRot.Roll = 0.f;
			PlayerRot.Yaw = PlayerRot.Yaw + 90.f;
			PlayerRot.Pitch = -90.f+10;
		//	for (int32 i = 0; i < decals.Num(); i++)
		//	{
		//	locations[i] =	decals[i]->GetActorLocation();
		//	}
			//h.Yaw = PlayerRot.Quaternion().Y;
			for (int32 i = 0; i < decals.Num(); i++)
			{
				//decals[i]->AttachToActor(decalArrow,  FAttachmentTransformRules(EAttachmentRule::KeepRelative,true), NAME_None);
			}
			decalArrow->SetActorRotation(PlayerRot);
		//	decal->SetDecalMaterial(Material);
	//	{
		//	UE_LOG(LogTemp, Warning, TEXT("No decal spawned"));
			UE_LOG(LogTemp, Warning, TEXT("Marin11123 %s"), *PlayerRot.ToString());
		}
	}
//	TestT();
}

void AMyRTSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("LeftMouse", IE_Pressed, this, &AMyRTSPlayerController::SelectionPressed);
	InputComponent->BindAction("RightMouse", IE_Pressed, this, &AMyRTSPlayerController::EnableFormation);
	InputComponent->BindAction("LeftMouse", IE_Released, this, &AMyRTSPlayerController::SelectionReleased);
	InputComponent->BindAction("RightMouse", IE_Released, this, &AMyRTSPlayerController::MoveReleased);
	InputComponent->BindAction("New", IE_Pressed, this, &AMyRTSPlayerController::SpawnArrow);
}

void AMyRTSPlayerController::EnableFormation() 
{
	isFormationSet = true;
}

void AMyRTSPlayerController::SelectionPressed()
{
	if(Hud!=nullptr){
		Hud->InitialPoint = Hud->GetMousePossition();
		Hud->bStartSelect = true;
	}
	activateLeft = true;
}

void AMyRTSPlayerController::SelectionReleased()
{
	if (decalArrow) 
	{
	//	decalArrow->SetLifeSpan(3.0f);
	}
	if (decalUnit)
	{
	//	decalUnit->SetLifeSpan(3.0f);
	}

	if (Hud != nullptr) 
	{
		Hud->bStartSelect = false;
		SelectedActors = Hud->FoundActors;
	}
	activateLeft = false;
}

void AMyRTSPlayerController::MoveReleased()
{
	
	if(decalArrow){
	//	decalArrow->SetLifeSpan(1.0f);
	}
	if (SelectedActors.Num()>0)
	{
		for(int32 i = 0; i < SelectedActors.Num(); i++) 
		{
			FHitResult Hit;
			GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Hit);
			FVector Movelocation = Hit.Location + FVector(i / 2 * 100, i % 2 * 100, 0);
			locations.Add(Movelocation);
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(SelectedActors[i]->GetController(), Movelocation);
			
		}
	}
	activateRight = false;
}

void AMyRTSPlayerController::Test()
{
	activateRight = true;
//	FHitResult Result;
	for (int32 i = 0; i < SelectedActors.Num(); i++)
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Hit);
		FVector Movelocation = Hit.Location + FVector(i / 2 * 100, i % 2 * 100, 0);
		DrawDebugSphere(GetWorld(), Movelocation, 25, 10, FColor::Red, false, 0, 0, 0);
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(SelectedActors[i]->GetController(), Movelocation);
	}
	//if (toSpawn)
	//{
		UWorld* world = GetWorld();
		TArray<AActor*> FoundActors;
		if (world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			FRotator rotator;
			FVector spawnLocation;
			
			GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, Result);
			//UObject* ClassPackage = ANY_PACKAGE;
			
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);

			//for (AActor* TActor : FoundActors)
			//{
			//	AMyActor* MyActor = Cast<AMyActor>(TActor);
			//	AMyActor* MyActor = Cast<AMyActor>(TActor);
			FString f;
			for (int32 i = 0; i < FoundActors.Num(); i++)
			{
				f = FoundActors[i]->GetName();
				UE_LOG(LogTemp, Warning, TEXT("Marin11123 %s"), *f);
			}
			FoundActors[18]->SetActorLocation(Result.Location);
			 f = FString::FromInt(FoundActors.Num());
			 UE_LOG(LogTemp, Warning, TEXT("Marin11123 %s"), *f);
			
		    //	FoundActors[1]->GetArchetype();
			//	if (MyActor != nullptr)
			//	{
			//	}
			//  Do what ever you need with your MyActor
		    //	}
			//  auto ObjectToSpawn = FindObject<UMaterial>(toSpawn,TEXT("Material'/Game/Formation/FormationArrow'"));

			world->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, Result);
			AMyActor* a = world->SpawnActor<AMyActor>(AMyActor::StaticClass(), Result.Location, rotator, spawnParams); //''Works
			//auto ObjectToSpawn = FindObject<UObject>(ClassPackage, TEXT("Material'/Game/Formations/FormationArrow'"));
			UE_LOG(LogTemp, Warning, TEXT("MMM %s"), *Result.Location.ToString());
		}
			//}
			//	FHitResult Result;
			//  GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, Result);

			//	FVector Location(0.0f, 0.0f, 0.0f);
			//	FRotator Rotation(0.0f, 0.0f, 0.0f);
			//	FActorSpawnParameters SpawnInfo;
			//	world->SpawnActor<AActor>(*FoundActors[18],Location, Rotation, SpawnInfo);
	    UMaterial* Material = LoadObject<UMaterial>(NULL, TEXT("Material'/Game/TopDownCPP/Blueprints/Arrow.Arrow'"));
		decalArrow = GetWorld()->SpawnActor<ADecalActor>(Result.Location, FRotator());
			//  ADecalActor* decal = GetWorld()->SpawnActor<ADecalActor>(Result.Location, FRotator());
		if (decalArrow)
		{
			decalArrow->SetDecalMaterial(Material);
		//	decal->SetLifeSpan(2.0f);
			decalArrow->GetDecal()->DecalSize = FVector(32.0f, 64.0f, 64.0f);
		//	m_previousActionDecal = decal;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No decal spawned"));
		}
}      


void AMyRTSPlayerController::TestTwo()
{
	UMaterial* Material = LoadObject<UMaterial>(NULL, TEXT("Material'/Game/TopDownCPP/Blueprints/Arrow.Arrow'"));
//	FHitResult Result;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, Result);
	decalArrow = GetWorld()->SpawnActor<ADecalActor>(Result.Location, FRotator());
	//ADecalActor* decal = GetWorld()->SpawnActor<ADecalActor>(Result.Location, FRotator());
	if (decalArrow)
	{
		decalArrow->SetDecalMaterial(Material);
		decalArrow->SetLifeSpan(4.0f);
		decalArrow->GetDecal()->DecalSize = FVector(32.0f, 64.0f, 64.0f);
	//m_previousActionDecal = decal;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No decal spawned"));
	}
}

void AMyRTSPlayerController::TestT()
{
//	UMaterial* Material = LoadObject<UMaterial>(NULL, TEXT("Material'/Game/TopDownCPP/Blueprints/Arrow.Arrow'"));
//	FHitResult Result;
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, Result);
/*	UE_LOG(LogTemp, Warning, TEXT("Marin11123 %s"), *Result.Location.ToString());

	ADecalActor* decal = GetWorld()->SpawnActor<ADecalActor>(Result.Location, FRotator());

	if (decal)
	{
		decal->SetDecalMaterial(Material);
		//	decal->SetLifeSpan(4.0f);
		decal->GetDecal()->DecalSize = FVector(32.0f, 64.0f, 64.0f);
		//	m_previousActionDecal = decal;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No decal spawned"));
	}
	\*/
	//decal->GetActorLocation()->FindLookAtRotation()
	FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(decalArrow->GetActorLocation(), Result.Location);
	//decal->EditorApplyRotation(PlayerRot,true,true,true);
	//decal->SetActorRotation();
	FQuat f;
	FRotator h;
	//h.Yaw = PlayerRot.Yaw + decal->GetActorRotation().Yaw+50;
	h.Yaw = PlayerRot.Yaw;
	h.Roll = decalArrow->GetActorRotation().Roll;
	h.Pitch = decalArrow->GetActorRotation().Pitch;
	//f.Z = PlayerRot.Yaw + decal->GetActorRotation().Yaw;
	decalArrow->SetActorRotation(h);
	//UE_LOG(LogTemp, Warning, TEXT("Marin11123 %s"), h.ToString());
}

void AMyRTSPlayerController::SpawnArrow() 
{
	if (isFormationSet && activateLeft && SelectedActors.Num() > 0)
	{
		UMaterial* Arrow = LoadObject<UMaterial>(NULL, TEXT("Material'/Game/TopDownCPP/Blueprints/Arrow.Arrow'"));
	//	FHitResult Result;

		GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Camera), true, Result);
		decalArrow = GetWorld()->SpawnActor<ADecalActor>(Result.Location, FRotator(0.f,0,0));
		
		if (decalArrow)
		{
			decalArrow->SetDecalMaterial(Arrow);
			//decal->SetActorRotation(FRotator(0.f,90.f,90.f));
			//decal->SetLifeSpan(4.0f);
			decalArrow->GetDecal()->DecalSize = FVector(64.0f, 128.0f, 128.0f);
			//	m_previousActionDecal = decal;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No decal spawned"));
		}
		activateRight = true;
	}
	UMaterial* UnitSpace = LoadObject<UMaterial>(NULL, TEXT("Material'/Game/TopDownCPP/Blueprints/LocationIndicator.LocationIndicator'"));
	
	for (int32 i = 0; i < SelectedActors.Num(); i++)
	{
	//	decalUnit->AttachToActor(decalArrow, FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), NAME_None);
		FVector Hit= Result.Location+FVector(-400,150,0);
	//	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, Result);
		FVector Movelocation = Hit + FVector(i / 3 * 100, i % 3 * 100, 0);
	//	FVector Movelocation2 = locations[1];
		decalUnit = GetWorld()->SpawnActor<ADecalActor>(Movelocation, FRotator(0,0,0));
		decalUnit->SetActorLocation(Movelocation);
		//decalUnit->SetActorRotation(FRotator(0, 0, 0));
		decalUnit->SetDecalMaterial(UnitSpace);
		//decalUnit->GetDecal()->DecalSize = FVector(0, 0, 0);
		//decalUnit->GetDecal()->DecalSize = FVector(0, 0, 0);
		//decalUnit->AttachToActor(decalArrow, FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), NAME_None);
	//	decalUnit->SetActorLocation(Movelocation); 
		decalUnit->GetDecal()->DecalSize = FVector(30, 30, 30);
	//	decals.Add(decalUnit);
		//DrawDebugSphere(GetWorld(), Movelocation, 25, 10, FColor::Red, false, 0, 0, 0);
//		UAIBlueprintHelperLibrary::SimpleMoveToLocation(SelectedActors[i]->GetController(), Movelocation);
	}
}
