// Fill out your copyright notice in the Description page of Project Settings.


#include "Fraction.h"
#include "DrawDebugHelpers.h"
#include "SceneManagement.h"

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
	if (!Denominator) { return; } // If denominator is 0 return
	switch (Format)
	{
	case DisplayFormat::WireFrameCircle:
	case DisplayFormat::Circle:
		DrawCircle();
		break;
	case DisplayFormat::Rectangle:
		DrawRectangle();
		break;
	default:
		DrawCircle();
		break;
	}
}


void AFraction::DrawCircle()
{
	DrawDebugCircle(GetWorld(),
	                GetActorLocation(),
	                Radius,
	                360,
	                SecondaryColor,
	                false,
	                -1.0f,
	                0,
	                0,
	                GetActorForwardVector(),
	                GetActorUpVector(),
	                false
	);

	if (Denominator <= 1 || Denominator == Numerator) { return; } // If denominator is 1 or less return
	Segment = 360 / Denominator; //angle segment
	for (int i = 0; i < Denominator; i++)
	{
		float rotationAngle = Segment * i;
		FVector Vector1 = GetActorForwardVector().RotateAngleAxis(-rotationAngle, GetActorRightVector());
		DrawDebugLine(GetWorld(),
		              GetActorLocation(),
		              GetActorLocation() + Vector1 * Radius,
		              i <= Numerator && Numerator != 0? PrimaryColor : SecondaryColor,
		              false,
		              -1.0f);

		if(Format != DisplayFormat::Circle){continue;} //If not a full circle continue looping

		/*TArray<FVector> vertices;
	//vertices.SetNum(3);
	vertices.Emplace(0,0,0);
	vertices.Emplace(100,0,0);
	vertices.Emplace(50,0,100);
	vertices.Emplace(0,0,200);
	vertices.Emplace(100,0,0);

	TArray<int32> indices;
	//indices.SetNum(3);
	indices.Emplace(2);
	indices.Emplace(1);
	indices.Emplace(0);
	indices.Emplace(4);
	indices.Emplace(3);
	indices.Emplace(2);
	DrawDebugMesh(GetWorld(),
				vertices,
				indices,
				PrimaryColor);*/

		
	}
}


void AFraction::DrawRectangle()
{
	Segment = Radius / Denominator;
	//Draw Square
	const FVector center= GetActorLocation();
	const FVector halfWidth = GetActorForwardVector() * Radius/2;
	const FVector halfHeight = GetActorUpVector() * Radius/2;
	const FVector vertex1(center -  halfWidth + halfHeight);
	const FVector vertex2(center +  halfWidth + halfHeight);
	const FVector vertex3(center -  halfWidth - halfHeight);
	const FVector vertex4(center +  halfWidth - halfHeight);
	DrawDebugLine(GetWorld(), vertex1, vertex2, SecondaryColor);
	DrawDebugLine(GetWorld(), vertex3, vertex4, SecondaryColor);
	DrawDebugLine(GetWorld(), vertex1, vertex3, SecondaryColor);
	DrawDebugLine(GetWorld(), vertex2, vertex4, SecondaryColor);

	//Draw Bars
	if (Denominator <= 1 || Denominator == Numerator) { return; } // If denominator is 1 or less return
	FVector top = vertex1;
	FVector bottom = vertex3;
	const FVector dx = GetActorForwardVector() * Segment;
	for (int i = 0; i < Denominator; i++)
	{
		DrawDebugLine(GetWorld(), top, bottom,
						i <= Numerator && Numerator != 0? PrimaryColor : SecondaryColor);
		top += dx;
		bottom += dx;
	}

	
	
	
	
				
}
