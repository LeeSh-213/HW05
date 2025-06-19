#include "HW.h"
#include "Engine/World.h"  
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h" 
#include "Math/UnrealMathUtility.h"  








AHW::AHW()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AHW::BeginPlay()
{
	Super::BeginPlay();
	
	FVector2D Start(0, 0);
	FVector2D Target(1, 1);

	if (IsMovable(Start, Target))
	{
		FVector SpawnLocation = FVector(Target.X * 0.f, Target.Y * 0.f, 1.f);  
	}

	
	Move();
}

bool AHW::IsMovable(const FVector2D& Current, const FVector2D& Target) const
{
	return (FMath::Abs(Target.X - Current.X) < 2 && FMath::Abs(Target.Y - Current.Y) < 2);
}

void AHW::TrySpawnActor(const FVector& Location)
{
	UWorld* World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		AHW* NewActor = World->SpawnActor<AHW>(GetClass(), Location, FRotator::ZeroRotator, SpawnParams);

		if (NewActor)
		{
		}
	}
}
int32 AHW::Step() const
{
	return FMath::RandBool() ? 1 : 0;
}

void AHW::Move()
{
	FVector2D Current(0, 0);

	for (int i = 0; i < 10; i++)
	{
		int32 dx = Step();
		int32 dy = Step();

		FVector2D Target(Current.X + dx, Current.Y + dy);

		if (IsMovable(Current, Target))
		{
			Current = Target;
			UE_LOG(LogTemp, Warning, TEXT("Step %d: 현재 위치는 (%.0f, %.0f)입니다."), i + 1, Current.X, Current.Y);


			FVector SpawnLocation = FVector(Current.X * 100.f, Current.Y * 100.f, 0.f); 
			TrySpawnActor(SpawnLocation);

		}

	}
}




void AHW::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

