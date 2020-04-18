#pragma once

class Car
{
protected:
	float fuelCapacity;
	float fuelConsumption;
	float avgSpeedRainy;
	float avgSpeedSunny;
	float avgSpeedSnowy;

public:
	//~Car();
	virtual const char* getCarName() = 0;
	virtual float getFuelCapacity() = 0;
	virtual float getFuelConsumption() = 0;
	virtual float getAvgSpeedRainy() = 0;
	virtual float getAvgSpeedSunny() = 0;
	virtual float getAvgSpeedSnowy() = 0;
};