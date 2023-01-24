// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fraction.generated.h"

UCLASS()
class MATHHELPER_API AFraction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFraction();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Props", meta = (AllowPrivateAccess = "true"))
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props", meta = (AllowPrivateAccess = "true"))
	int Numerator = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props", meta = (AllowPrivateAccess = "true"))
	uint8 Denominator = 1;

	int SegmentAngle;
};
