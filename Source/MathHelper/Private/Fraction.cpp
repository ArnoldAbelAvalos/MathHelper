// Fill out your copyright notice in the Description page of Project Settings.


#include "Fraction.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFraction::AFraction()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFraction::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFraction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Denominator) { return; }

	SegmentAngle = 360 / Denominator;
	DrawDebugCircle(GetWorld(),
	                GetActorLocation(),
	                Radius,
	                360,
	                FColor::Red,
	                false,
	                -1.0f,
	                0,
	                0,
	                GetActorForwardVector(),
	                GetActorUpVector(),
	                false
	);

	if (Denominator > 1)
	{
		for (unsigned int i = 0; i < Denominator; i++)
		{
			float rotationAngle = SegmentAngle * i;
			FVector Vector1 = GetActorForwardVector().RotateAngleAxis(rotationAngle, GetActorRightVector());
			DrawDebugLine(GetWorld(),
			              GetActorLocation(),
			              GetActorLocation() + Vector1 * Radius,
			              FColor::Green,
			              false,
			              -1.0f);
		}
	}
}
