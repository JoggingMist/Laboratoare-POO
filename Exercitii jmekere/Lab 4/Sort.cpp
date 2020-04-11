#include "Sort.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

using namespace std;

Sort::Sort(int min, int max)
{
	int i;
	nr = 5;
	Array = new int[nr];
	srand(time(NULL));
	for (i = 0; i < nr; i++)
	{
		Array[i] = rand() % max + min;
		cout << Array[i] << " ";
	}
}

//Sort::Sort(int* array, int count)
//{
//	Array = new int[count];
//	nr = count;
//	for (int i = 0; i < nr; i++)
//	{
//		Array[i] = array[i];
//	}
//}

Sort::Sort(int count, ...)
{
	int val;
	Array = new int[count];
	nr = count;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		val = va_arg(vl, int);
		cout << val << " ";
	}
	va_end(vl);
}

Sort::Sort(char* s, int count)
{
	int i = 0;
	Array = new int[count];
	nr = count;
	char* p;
	p = strtok(s, ",");
	while (p)
	{
		Array[i++] = atoi(p);
		cout << Array[i-1] << " ";
		p = strtok(NULL, ",");
	}
}