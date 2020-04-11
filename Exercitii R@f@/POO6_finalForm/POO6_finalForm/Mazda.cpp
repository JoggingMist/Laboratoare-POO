#include "Mazda.h"
#include <iostream>
Mazda::Mazda()
{
	fuelCapacity = 90;
	fuelConsumption = 12.2f;
	averageSpeedOnSunny = 70;
	averageSpeedOnRain = 69;
	averageSpeedOnSnow = 64;
}

char* Mazda::carName()
{
	char p[] = "Mazda";
	char* output = new char[strlen(p) + 1];
	strcpy(output, p);
	return output;
}

float Mazda::getfuelCapacity()
{
	return fuelCapacity;
}

float Mazda::getfuelConsumption()
{
	return fuelConsumption;
}

float Mazda::getaverageSpeedOnSunny()
{
	return averageSpeedOnSunny;
}

float Mazda::getaverageSpeedOnRain()
{
	return averageSpeedOnRain;
}

float Mazda::getaverageSpeedOnSnow()
{
	return averageSpeedOnSnow;
}