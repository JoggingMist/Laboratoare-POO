#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	masini = new Car*[10];
	Length = 0;
	clasament = new int[10];
	nrMasini = 0;
	weather = Weather::Rainy;
}

void Circuit::AddCar(Car* masina)
{
	if (nrMasini < 10)
	{
		masini[nrMasini++] = masina;
		cout << "Bravo prostule, a intrat " << masina->getCarName() << " lu Tata " << endl;
	}
	else 
		cout << "Ba prostule, vezi ca nu mai ai loc!" << endl;
}

void Circuit::SetWeather(Weather w)
{
	weather = w;
}

void Circuit::SetLength(int l)
{
	Length = l;
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < nrMasini; i++)
		if ((masini[i]->getFuelCapacity() * 100) / masini[i]->getFuelConsumption() < Length)
			cout << masini[i]->getCarName() << " lu Tataia nu a terminat cursa" << endl;
}

void Circuit::Race()
{
	int index = 0;

	if (weather == Weather::Rainy)
		for (int i = 0; i < nrMasini; i++)
		{
			if ((masini[i]->getFuelCapacity() * 100) / masini[i]->getFuelConsumption() > Length)
			{
				clasament[index] = Length * 60 / masini[i]->getAvgSpeedRainy();
				index++;
			}
		}
	if (weather == Weather::Sunny)
		for (int i = 0; i < nrMasini; i++)
		{
			if ((masini[i]->getFuelCapacity() * 100) / masini[i]->getFuelConsumption() > Length)
			{
				clasament[index] = Length * 60 / masini[i]->getAvgSpeedSunny();
				index++;
			}
		}
	if(weather == Weather::Snowy)
		for (int i = 0; i < nrMasini; i++)
		{
			if ((masini[i]->getFuelCapacity() * 100) / masini[i]->getFuelConsumption() > Length)
			{
				clasament[index] = Length * 60 / masini[i]->getAvgSpeedSnowy();
				index++;
			}
		}
}
