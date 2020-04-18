#include <iostream>
#include "Dacia.h"
#include "Mercedes.h"
#include "Circuit.h"
using namespace std;

int main()
{
    Circuit c;
    c.SetLength(584);
    c.SetWeather(Weather::Rainy);
    c.AddCar(new Dacia());
    //c.AddCar(new Toyota()); 
    c.AddCar(new Mercedes());
    //c.AddCar(new Ford());
    //c.AddCar(new Mazda());
    c.Race();
    //c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
    c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
    
    /* Trebuia : O sortare cum trebuie, care sa afiseze masina si timpul;
                 Adaugate restul masinilor ( copy - paste ) */

    return 0;
}