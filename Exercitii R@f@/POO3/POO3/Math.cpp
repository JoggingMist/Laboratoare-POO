#include "Math.h"
#include <stdarg.h>
#include <iostream>
using namespace std;

int Math::Add(int a,int b)
{ 
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	va_list v;
	va_start(v, count);
	int Sum = 0;
	for (int i = 1; i <= count; ++i)
	{
		Sum += va_arg(v, int);
	}
	va_end(v);
	return Sum;
}

char* Math::Add(const char* firstString, const char* lastString)
{
	if (firstString == nullptr || lastString == nullptr)
		return nullptr;
	int i, j, n, m, k;
	for (n = 0; firstString[n]; ++n);
	for (m = 0; lastString[m]; ++m);

	char* Output= new char[n+m];
	
	for (k = 0, i = 0, j = 0; k < n + m; ++k)
	{
		if (k < n)
			Output[k] = firstString[i++];
		else
			Output[k] = lastString[j++];
	}
	Output[k] = '\0';

	return Output;
}
