#include <iostream>
#include <string.h>
#include "Number.h"


using namespace std;

Number::Number(const char* value, int base)
{
	baza = base;
	int length = strlen(value);

	s = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		s[i] = value[i];
	}
	s[length] = '\0';
	cout << s;
}

Number::~Number()
{
	delete[] s;
}

//Number::SwitchBase()
//{
//
//}

//int Number::GetDigitsCount() 
//{
//	return 1;
//}