#include "Car.h"

class Dacia :public Car
{
public:
	Dacia();
	char* carName() override;

	float getfuelCapacity() override;
	float getfuelConsumption() override;
	float getaverageSpeedOnSunny() override;
	float getaverageSpeedOnRain() override;
	float getaverageSpeedOnSnow() override;
};