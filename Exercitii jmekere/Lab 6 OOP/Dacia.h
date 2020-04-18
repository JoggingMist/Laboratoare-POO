#pragma once
#include "Car.h"

class Dacia : public Car
{
public:
	Dacia();
	const char* getCarName() override;
	float getFuelCapacity() override;
	float getFuelConsumption() override;
	float getAvgSpeedSunny() override;
	float getAvgSpeedSnowy() override;
	float getAvgSpeedRainy() override;
};