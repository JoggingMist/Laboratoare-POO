#pragma once
#include "Car.h"
#include "Dacia.h"
#include "Mercedes.h"
#include "Weather.h"

class Circuit
{
	int nrMasini;
	Car** masini;
	int Length;
	Weather weather;
	int* clasament;

public:
	Circuit();
	void AddCar(Car* masina);
	void SetWeather(Weather);
	void SetLength(int);
	void ShowWhoDidNotFinish();
	void Race();


	
	
};

