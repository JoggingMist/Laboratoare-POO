#include <iostream>
#include <math.h>
#include "Number.h"

using namespace std;

char* convertIntToString(int x) //x must be decimal
{
	char* Output;
	short Dimension = (short)log10(x) + 1;
	Output = new char[Dimension + 1];
	for (int index = Dimension - 1; index >= 0; index--)
	{
		Output[index] = x % 10 + '0';
		x /= 10;
	}
	Output[Dimension] = '\0';
	return Output;
}

Number::Number(const char* value, int base)
{
	Base = base;
	
	int length = strlen(value);
	Value = new char[length + 1];

	for (int index = 0; index <= length; index++)
	{
		Value[index] = value[index];
	}

	Decimal = 0;
	for (int index = length - 1; index >= 0; index--)
	{
		Decimal = Decimal + (int)pow(Base, length - index - 1) * 
			((Value[index] >= '0' && Value[index] <= '9') ? 
				Value[index] - '0' : 
				Value[index] - 'A' + 10);
	}
}

Number::Number(const int value) :Number(convertIntToString(value), 10) {}

Number::Number() : Number(convertIntToString(rand() % 100), 10) {};

Number::~Number()
{
	delete[] Value;
}

Number::Number(const Number& n)//consturctor de copiere
{
	Base = n.Base;
	Decimal = n.Decimal;

	//delete[] Value;
	int length = strlen(n.Value);
	Value = new char[length + 1];

	for (int index = 0; index <= length; index++)
		Value[index] = n.Value[index];
}

Number::Number(Number&& n)//constructor de mutare
{
	Base = n.Base;

	Decimal = n.Decimal;
	Value = n.Value;

	delete[] n.Value;
	//n.Value = nullptr;
}
void Number::operator=(const Number& n)
{
	Base = n.Base;
	Decimal = n.Decimal;

	delete[] Value;
	int length = strlen(n.Value);
	Value = new char[length + 1];

	for (int index = 0; index <= length; index++)
		Value[index] = n.Value[index];
}

void Number::operator=(int x)
{
	const char* p = convertIntToString(x);
	Number newObj(p, 10);
	newObj.SwitchBase(Base);
	
	
	int length = strlen(newObj.Value);
	delete[] Value;
	Value = new char[length + 1];
	for (int index = 0; index <= length; index++)
		Value[index] = newObj.Value[index];

	Decimal = newObj.Decimal;

	delete[] p;
}

void Number::operator=(const char* n)
{
	Number newObj(n, 10);
	strcpy(Value, newObj.Value);
	Decimal = newObj.Decimal;
	Base = newObj.Base;
}

Number Number::operator+(const Number& n)
{
	int d1, d2, b1, b2;
	d1 = Decimal;
	d2 = n.Decimal;
	b1 = Base;
	b2 = n.Base;


	int newBase = (b1>b2)?b1 : b2;
	const char* newValue = convertIntToString(d1 + d2);
	Number newObj(newValue, 10);
	
	newObj.SwitchBase(newBase);

	return newObj;
}

void Number::operator+=(const Number& n)
{
	Number newObj = (*this) + n;
	(*this) = newObj;
}

Number Number::operator-(const Number& n)
{
	int d1, d2, b1, b2;
	d1 = Decimal;
	d2 = n.Decimal;
	b1 = Base;
	b2 = n.Base;


	int newBase = (b1 > b2) ? b1 : b2;
	const char* newValue = convertIntToString(d1 - d2);
	Number newObj(newValue, 10);

	newObj.SwitchBase(newBase);

	return newObj;
}

void Number::operator-=(const Number& n)
{
	Number newObj = (*this) - n;
	(*this) = newObj;
}


bool Number::operator==(const Number& n)
{
	if (Decimal == n.Decimal)return true;
	return false;
}
bool Number::operator<=(const Number& n)
{
	if (Decimal <= n.Decimal)return true;
	return false;
}
bool Number::operator>=(const Number& n)
{
	if (Decimal >= n.Decimal)return true;
	return false;
}
bool Number::operator>(const Number& n)
{
	if (Decimal > n.Decimal)return true;
	return false;
}
bool Number::operator<(const Number& n)
{
	if (Decimal < n.Decimal)return true;
	return false;
}

void Number::operator--(int)//n--
{
	int length = strlen(Value);
	char* p = new char[length];
	memcpy(p, Value, length-1);
	p[length-1] = '\0';

	Number newObj(p, Base);
	Value = p;
	Base = newObj.Base;
	Decimal = newObj.Decimal;
}

void Number::operator--()//--n
{
	int length = strlen(Value);
	char* p = new char[length+1];
	memcpy(p, Value, length+1);
	for (int index = 0; index < length; index++)
		p[index] = p[index + 1];

	Number newObj(p, Base);
	Value = p;
	Base = newObj.Base;
	Decimal = newObj.Decimal;
}

char Number::operator[](const int x)
{
	if (x >= 0 && x <= strlen(Value) - 1)
		return Value[x];
}



void Number::SwitchBase(int newBase)
{
	int newLenght = (int)(log(Decimal) / log(newBase))+1;

	delete[] Value;
	Value = new char[newLenght + 1];
	Base = newBase;

	int auxDecimal = Decimal;

	int r;
	for (int index = newLenght - 1; index >= 0; index--)
	{
		r = auxDecimal % newBase;
		auxDecimal /= newBase;
		Value[index] = (r >= 0 && r <= 9) ? r + '0' : r + 'A' - 10;
	}
	Value[newLenght] = '\0';
}

void Number::Print() const
{
	printf("%s\n", Value);
}

int  Number::GetDigitsCount() const
{
	int index;
	for (index = 0; Value[index]; index++);
	return index;
}


int  Number::GetBase() const
{
	return Base;
}