// Fill out your copyright notice in the Description page of Project Settings.


#include "PanelRender.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>




// Sets default values
APanelRender::APanelRender()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//sm_plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plane"));
	UE_LOG(LogTemp, Warning, TEXT("CPP constructor"));

	MyBox = FBox(FVector(0, 0, 0), FVector(200, 200, 200));


}

void APanelRender::BP_LOG(FString text)
{
	GetName();
	UE_LOG(LogTemp, Warning, TEXT("BP_LOG: %s"), *text);
}

// Called when the game starts or when spawned
void APanelRender::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay 1"));
	//std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay 2"));

	test();

	//DrawDebugLine(GetWorld(), LinkStart, LinkEnd,
	//	FColor(255, 0, 0), false, -1, 0, 10);

	//DrawDebugPoint(GetWorld(), LocationOne, 200, FColor(52, 220, 239), true);

	//DrawDebugSphere(GetWorld(), LocationTwo, 200, 26, FColor(181, 0, 0), true, -1, 0, 2);

	//DrawDebugCircle(GetWorld(), CircleMatrix, 200, 50, FColor(0, 104, 167), true, -1, 0, 10);

	//DrawDebugCircle(GetWorld(), LocationFour, 200, 50, FColor(0, 0, 0), true, -1, 0, 10);

	//DrawDebugSolidBox(GetWorld(), MyBox, FColor(20, 100, 240), MyTransform, true);

	//DrawDebugBox(GetWorld(), LocationFive, FVector(100, 100, 100), FColor::Purple, true, -1, 0, 10);

	//DrawDebugLine(GetWorld(), LocationTwo, LocationThree, FColor::Emerald, true, -1, 0, 10);

	//DrawDebugDirectionalArrow(GetWorld(), FVector(-300, 600, 600), FVector(-300, -600, 600), 120.f, FColor::Magenta, true, -1.f, 0, 5.f);

	//DrawDebugCrosshairs(GetWorld(), FVector(0, 0, 1000), FRotator(0, 0, 0), 500.f, FColor::White, true, -1.f, 0);

}

// Called every frame
void APanelRender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

range_t* APanelRender::createRange(size_t from, size_t to)
{
	if (from < to) {
		range_t *range = new range_t(to - from);
		std::for_each(range->begin(), range->end(), [&from](int& d) {
			d = from;
			from++;
		});
		return range;
	}
	return nullptr;
}

range_t* APanelRender::createSimpleDigit(range_t* range)
{
	range_t *filterRange = new range_t;
	for (size_t i = 0; i < range->size(); i++) {
		if (range->at(i) != 0 && range->at(i) != 1) {
			filterRange->push_back(range->at(i));
			for (size_t p = i * 2; p < range->size(); p+=i) {
				range->at(p) = 0;
			}
		}
	}
	return filterRange;
}

void APanelRender::printRange(range_t* range)
{
	FString str;
	for (size_t i = 0; i < range->size(); i++) {
		str += FString::FromInt(range->at(i)) + FString(" ");			
	}
	UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
}


void APanelRender::test()
{



	FVector GetTargetLocation = this->GetTargetLocation();
	FVector GetActorLocation = this->GetActorLocation();
	FVector LinkEnd = this->GetTransform().GetLocation();
	UE_LOG(LogTemp, Warning, TEXT("GetTargetLocation %s"), *GetTargetLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("GetActorLocation %s"), *GetActorLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("this->GetTransform().GetLocation() %s"), *LinkEnd.ToString());

	DrawDebugPoint(GetWorld(), LinkEnd, 10, FColor(52, 220, 239), true);

	range_t *range = createRange(0, 100);
	range_t *simpleDgt = createSimpleDigit(range);
	FString str;
	printRange(simpleDgt);

}
