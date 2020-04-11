#include "Car.h"

class Toyota :public Car
{
public:
	Toyota();
	virtual char* carName() override;

	virtual float getfuelCapacity() override;
	virtual float getfuelConsumption() override;
	virtual float getaverageSpeedOnSunny() override;
	virtual float getaverageSpeedOnRain() override;
	virtual float getaverageSpeedOnSnow() override;
};