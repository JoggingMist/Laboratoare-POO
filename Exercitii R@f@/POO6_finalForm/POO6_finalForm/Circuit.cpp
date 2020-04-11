
#include "Circuit.h"
#include <stdio.h>

bool carPassTheRace(Car* c, int length)
{
	if (c->getfuelCapacity / c->getfuelConsumption * 100 >= length)
		return true;
	return false;
}

Circuit::Circuit()
{
	Cars = new Car * [10];
	Timings = new float[10];
	Length = 0;
	numberOfCars = 0;
	weather = Weather::Sunny;
}

Circuit::~Circuit()
{
	delete[] Cars;
}

void Circuit::SetLength(int l)
{
	Length = l;
}

void Circuit::SetWeather(Weather w)
{
	weather = w;
	//
}

void Circuit::AddCar(Car* c)
{
	if (numberOfCars < 10)
	{
		Cars[numberOfCars++] = c;
		printf("Masina %s a fost inregistrata cu succes.\n", c->carName());
	}
	else
	{
		printf("Numar de masini prea mare.\n");
	}
}

void Circuit::Race()
{
	float aveargeSpeed;
	float time;
	for (int index = 0; index < numberOfCars; index++)
	{
		switch (weather)
		{
		case Weather::Sunny:
			aveargeSpeed = Cars[index]->getaverageSpeedOnSunny();
			break;

		case Weather::Rain:
			aveargeSpeed = Cars[index]->getaverageSpeedOnRain();
			break;

		case Weather::Snow:
			aveargeSpeed = Cars[index]->getaverageSpeedOnSnow();
			break;
		}

		if (carPassTheRace(Cars[index], Length))
			Timings[index] = (float)Length / aveargeSpeed;
		else
			Timings[index] = 0;
	}
}

void Circuit::ShowFinalRanks()
{
	for (int index = 0; index < numberOfCars; index++)
	{
		printf("Car %d: %s scored %f hours at the race.\n", index, Cars[index]->carName(), Timings[index]);
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int index = 0; index < numberOfCars; index++)
	{
		if (!carPassTheRace(Cars[index], Length))
			printf("Car %d: %s have not passed the race.\n", index, Cars[index]->carName());
	}
}