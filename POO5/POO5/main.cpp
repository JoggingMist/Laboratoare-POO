#include <iostream>
#include "Number.h"
using namespace std;

int main()
{
	Number caine("10111", 2);
	Number pisica("325", 6);
	
	caine = caine + pisica;
	caine.Print();
	//caine.operator+(pisica);
	
}
