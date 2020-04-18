#pragma once
#include "Car.h"

class Mercedes : public Car
{
public:
	Mercedes();
	const char* getCarName() override;
	float getFuelCapacity() override;
	float getFuelConsumption() override;
	float getAvgSpeedSunny() override;
	float getAvgSpeedSnowy() override;
	float getAvgSpeedRainy() override;
};