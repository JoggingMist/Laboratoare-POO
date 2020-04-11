#ifndef CarH
#define CarH

class Car
{
protected:
	float fuelCapacity;
	float fuelConsumption;
	float averageSpeedOnSunny;
	float averageSpeedOnRain;
	float averageSpeedOnSnow;

public:
	virtual char* carName() = 0;
	virtual float getfuelCapacity() = 0;
	virtual float getfuelConsumption() = 0;
	virtual float getaverageSpeedOnSunny() = 0;
	virtual float getaverageSpeedOnRain() = 0;
	virtual float getaverageSpeedOnSnow() = 0;
};

#endif
