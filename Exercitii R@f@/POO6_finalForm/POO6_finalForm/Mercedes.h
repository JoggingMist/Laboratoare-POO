#include "Car.h"

class Mercedes :public Car
{
public:
	Mercedes();
	virtual char* carName() override;

	virtual float getfuelCapacity() override;
	virtual float getfuelConsumption() override;
	virtual float getaverageSpeedOnSunny() override;
	virtual float getaverageSpeedOnRain() override;
	virtual float getaverageSpeedOnSnow() override;
};
