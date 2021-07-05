// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TextureRenderTarget2D.h"
#include "DrawDebugHelpers.h"
#include <vector>


#include "PanelRender.generated.h"



using range_t = std::vector<int>;


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE4DRAW2D_API APanelRender : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APanelRender();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UStaticMeshComponent* sm_plane = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float testFloat;

	//UFUNCTION(BlueprintCallable, Category = "Setup")
	//void initialize(UStaticMeshComponent* mesh);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void BP_LOG(FString text);

	//TextureRenderTarget2D* renderTarget = nullptr;

	
	range_t* createRange(size_t from, size_t to);
	range_t* createSimpleDigit(range_t *range);
	void printRange(range_t *range);
	void test();


	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector LocationOne;

	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector LocationTwo;

	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector LocationThree;

	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector LocationFour;

	UPROPERTY(EditAnywhere, Category = "Locations")
		FVector LocationFive;

	UPROPERTY(EditAnywhere, Category = "Locations")
		FMatrix CircleMatrix;

	UPROPERTY(EditAnywhere, Category = "Locations")
		FBox MyBox;

	UPROPERTY(EditAnywhere, Category = "Locations")
		FTransform MyTransform;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
