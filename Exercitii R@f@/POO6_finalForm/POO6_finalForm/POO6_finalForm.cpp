#include <iostream>
#include "Circuit.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Weather.h"
using namespace std;

int main()
{
	Car** Cars;
	Cars = new  Car*[10];
	Cars[0] = new Dacia();
	Cars[1] = new Ford();
	Cars[2] = new Mazda();
	Cars[3] = new Mercedes();
	Cars[4] = new Toyota();

	for (int index = 0; index <= 4; index++)
	{
		cout << Cars[index]->carName() << endl;
		cout << Cars[index]->getfuelCapacity() << endl;
	}
}

