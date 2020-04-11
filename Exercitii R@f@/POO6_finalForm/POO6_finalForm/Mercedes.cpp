#include "Mercedes.h"
#include <iostream>

Mercedes::Mercedes()
{
	fuelCapacity = 80;
	fuelConsumption = 10.5f;
	averageSpeedOnSunny = 71;
	averageSpeedOnRain = 63;
	averageSpeedOnSnow = 61;
}

char* Mercedes::carName()
{
	char p[] = "Mercedes";
	char* output = new char[strlen(p) + 1];
	strcpy(output, p);
	return output;
}

float Mercedes::getfuelCapacity()
{
	return fuelCapacity;
}

float Mercedes::getfuelConsumption()
{
	return fuelConsumption;
}

float Mercedes::getaverageSpeedOnSunny()
{
	return averageSpeedOnSunny;
}

float Mercedes::getaverageSpeedOnRain()
{
	return averageSpeedOnRain;
}

float Mercedes::getaverageSpeedOnSnow()
{
	return averageSpeedOnSnow;
}