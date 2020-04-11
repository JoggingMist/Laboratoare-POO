#include "Ford.h"
#include <iostream>
Ford::Ford()
{
	fuelCapacity = 50;
	fuelConsumption = 10.2f;
	averageSpeedOnSunny = 100;
	averageSpeedOnRain = 90;
	averageSpeedOnSnow = 80;
}

char* Ford::carName()
{
	char p[] = "Ford";
	char* output = new char[strlen(p) + 1];
	strcpy(output, p);
	return output;
}

float Ford::getfuelCapacity()
{
	return fuelCapacity;
}

float Ford::getfuelConsumption()
{
	return fuelConsumption;
}

float Ford::getaverageSpeedOnSunny()
{
	return averageSpeedOnSunny;
}

float Ford::getaverageSpeedOnRain()
{
	return averageSpeedOnRain;
}

float Ford::getaverageSpeedOnSnow()
{
	return averageSpeedOnSnow;
}