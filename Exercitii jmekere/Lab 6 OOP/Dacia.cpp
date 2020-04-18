#include <iostream>
#include "Dacia.h"

Dacia::Dacia()
{
	fuelCapacity = 35.0f;	
	fuelConsumption = 6.0f;
	avgSpeedRainy = 60.0f;
	avgSpeedSunny = 80.0f;
	avgSpeedSnowy = 40.0f;
}

const char* Dacia::getCarName()
{
	return "Dacia";
}

float Dacia::getFuelCapacity()
{
	return fuelCapacity;
}

float Dacia::getFuelConsumption()
{
	return fuelConsumption;
}

float Dacia::getAvgSpeedRainy()
{
	return avgSpeedRainy;
}

float Dacia::getAvgSpeedSunny()
{
	return avgSpeedSunny;
}

float Dacia::getAvgSpeedSnowy()
{
	return avgSpeedSnowy;
}
