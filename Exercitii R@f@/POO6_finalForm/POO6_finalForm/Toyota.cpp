#include "Toyota.h"
#include <iostream>
Toyota::Toyota()
{
	fuelCapacity = 75;
	fuelConsumption = 10.2f;
	averageSpeedOnSunny = 73.2f;
	averageSpeedOnRain = 65;
	averageSpeedOnSnow = 62;
}

char* Toyota::carName()
{
	char p[] = "Toyota";
	char* output = new char[strlen(p)+1];
	strcpy(output, p);
	return output;
}

float Toyota::getfuelCapacity()
{
	return fuelCapacity;
}

float Toyota::getfuelConsumption()
{
	return fuelConsumption;
}

float Toyota::getaverageSpeedOnSunny()
{
	return averageSpeedOnSunny;
}

float Toyota::getaverageSpeedOnRain()
{
	return averageSpeedOnRain;
}

float Toyota::getaverageSpeedOnSnow()
{
	return averageSpeedOnSnow;
}