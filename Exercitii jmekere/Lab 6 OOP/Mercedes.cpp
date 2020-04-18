#include <iostream>
#include "Mercedes.h"

Mercedes::Mercedes()
{
	fuelCapacity = 75.8f;
	fuelConsumption = 12.3f;
	avgSpeedRainy = 75.0f;
	avgSpeedSunny = 127.8f;
	avgSpeedSnowy = 65.3f;
}

const char* Mercedes::getCarName()
{
	return "Mercedes";
}

float Mercedes::getFuelCapacity()
{
	return fuelCapacity;
}

float Mercedes::getFuelConsumption()
{
	return fuelConsumption;
}

float Mercedes::getAvgSpeedRainy()
{
	return avgSpeedRainy;
}

float Mercedes::getAvgSpeedSunny()
{
	return avgSpeedSunny;
}

float Mercedes::getAvgSpeedSnowy()
{
	return avgSpeedSnowy;
}
