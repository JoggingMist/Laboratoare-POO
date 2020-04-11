#include "Car.h"
#include "Weather.h"
class Circuit
{
	int Length;
	int numberOfCars;
	Weather weather;
	Car** Cars;
	float* Timings;

public:
	Circuit();
	~Circuit();
	void SetLength(int);
	void SetWeather(Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};