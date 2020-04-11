#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
	Math adunari;
	Math inmultiri;
	cout << adunari.Add(2,3) << endl;
	cout << adunari.Add(2,3,4) << endl;
	cout << adunari.Add(2.2,3.7) << endl;
	cout << adunari.Add(2.2,3.5,4.3) << endl;
	cout << inmultiri.Mul(2, 3) << endl;
	cout << inmultiri.Mul(2, 3, 4) << endl;
	cout << inmultiri.Mul(2.2, 3.5) << endl;
	cout << inmultiri.Mul(2.2, 3.5, 4.2) << endl;
	cout << adunari.Add(5, 1, 2, 3, 4, 5) << endl;
	cout << adunari.Add("Ana are mere", "Gigel are pere");
}