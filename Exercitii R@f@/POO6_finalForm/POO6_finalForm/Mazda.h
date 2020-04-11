#include "Car.h"

class Mazda :public Car
{
public:
	Mazda();
	virtual char* carName() override;

	virtual float getfuelCapacity() override;
	virtual float getfuelConsumption() override;
	virtual float getaverageSpeedOnSunny() override;
	virtual float getaverageSpeedOnRain() override;
	virtual float getaverageSpeedOnSnow() override;
};
