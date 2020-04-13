#include <iostream>
#include "Number.h"
using namespace std;

int main()
{
	Number caine("10111", 2);
	cout << endl;
	Number caine2("7", 10);
	int bazaMaiMare;

	if (caine.GetBase() > caine2.GetBase())
	{
		bazaMaiMare = caine.GetBase();
	}
	else
	{
		bazaMaiMare = caine2.GetBase();
	}

		caine = caine + caine2;
		//caine2.SwitchBase(16);
		caine2.Print();
}