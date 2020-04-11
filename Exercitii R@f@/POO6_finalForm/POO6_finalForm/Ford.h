#include "Car.h"

class Ford :public Car
{
public:
	Ford();
	char* carName() override;

	float getfuelCapacity() override;
	float getfuelConsumption() override;
	float getaverageSpeedOnSunny() override;
	float getaverageSpeedOnRain() override;
	float getaverageSpeedOnSnow() override;
};
