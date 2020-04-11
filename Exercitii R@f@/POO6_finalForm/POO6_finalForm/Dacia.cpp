#include "Dacia.h"
#include <iostream>
Dacia::Dacia()
{
	fuelCapacity = 60;
	fuelConsumption = 10.2f;
	averageSpeedOnSunny = 70;
	averageSpeedOnRain = 66;
	averageSpeedOnSnow = 60;
}

char* Dacia::carName() 
{
	char p[] = "Dacia";
	char* output = new char[strlen(p) + 1];
	strcpy(output, p);
	return output;
}

float Dacia::getfuelCapacity()
{
	return fuelCapacity;
}

float Dacia::getfuelConsumption()
{
	return fuelConsumption;
}

float Dacia::getaverageSpeedOnSunny()
{
	return averageSpeedOnSunny;
}

float Dacia::getaverageSpeedOnRain()
{
	return averageSpeedOnRain;
}

float Dacia::getaverageSpeedOnSnow()
{
	return averageSpeedOnSnow;
}