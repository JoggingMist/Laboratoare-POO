#include "Math.h"
#include <stdarg.h>


int Math::Add(int nr1, int nr2)
{
	return nr1 + nr2;
}

int Math::Add(int nr1, int nr2, int nr3)
{
	return nr1 + nr2 + nr3;
}

int Math::Add(double nr1, double nr2)
{
	double sum = nr1 + nr2;
	return (int)sum;
}

int Math::Add(double nr1, double nr2, double nr3)
{
	double sum = nr1 + nr2 + nr3;
	return (int)sum;
}

int Math::Mul(int nr1, int nr2)
{
	return nr1 * nr2;
}

int Math::Mul(int nr1, int nr2, int nr3)
{
	return nr1 * nr2 * nr3;
}

int Math::Mul(double nr1, double nr2)
{
	double prod = nr1 * nr2;
	return (int)prod;
}

int Math::Mul(double nr1, double nr2, double nr3)
{
	double prod = nr1 * nr2 * nr3;
	return (int)prod;
}

int Math::Add(int count,...)
{
	int i, value, sum=0;
	va_list v1;
	va_start(v1, count);
	for (i = 0; i < count; i++)
	{
		value = va_arg(v1, int);
		sum += value;
	}
	va_end(v1);
	return sum;
}

char* Math::Add(const char* p1, const char* p2)
{
	if (p1 == nullptr || p2 == nullptr)
		return nullptr;
	else
	{
		
		int lungime=0, i, k=0;
		for (i = 0; p1[i] != '\0'; i++) // strlen(p1)
			lungime++;
		for (i = 0; p2[i] != '\0'; i++) // strlen(p2)
			lungime++;
		char *total = new char[lungime+1]; // alocare spatiu de lungime + 1 caractere;
		// Type * nume = new Type - aloca spatiu pentru un element;
		// Type * nume = new Type[elemente] - basically un vector;
		// delete si delete[];
		for (i = 0; p1[i] != '\0'; i++)
		{
			total[k] = p1[i];
			k++;
		}

		for (i = 0; p2[i] != '\0'; i++)
		{
			total[k] = p2[i];
			k++;
		}
		total[k] = '\0';
		return total;
	}
}