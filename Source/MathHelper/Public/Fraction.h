// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fraction.generated.h"


UENUM(BlueprintType)
enum DisplayFormat
{
	WireFrameCircle UMETA(DisplayName = "WireframeCircle"),
	Circle UMETA(DisplayName = "Circle"),
	Rectangle UMETA(DisplayName = "Rectangle")
};

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Props", meta = (AllowPrivateAccess = "true", DisplayName = "Radius/Base"))
	float Radius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props", meta = (AllowPrivateAccess = "true"))
	int Numerator = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props", meta = (AllowPrivateAccess = "true"))
	int Denominator = 1;

	int Segment;




	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<DisplayFormat> Format = DisplayFormat::Circle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display", meta = (AllowPrivateAccess = "true"))
	FColor PrimaryColor = FColor::Blue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display", meta = (AllowPrivateAccess = "true"))
	FColor SecondaryColor = FColor::White;

	void DrawCircle();
	void DrawRectangle();

};
