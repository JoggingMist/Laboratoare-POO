#include "Sort.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdarg.h>


using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);


		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

Sort::Sort(int min, int max)
{
	Array = new int[5];
	Count = 5;
	srand(time(NULL));

	for (int i = 0; i < Count; i++)
	{
		Array[i] = rand() % (max-min) + min;
	}

}
Sort::Sort(int count, int* arr)
{
	Array = new int[count];
	Count = count;

	for (int i = 0; i < count; ++i)
	{
		Array[i] = arr[i];
	}
}
Sort::Sort(int count, ...)
{
	Array = new int[count];
	Count = count;
	va_list v;
	va_start(v,count);

	for (int i = 0; i < count; i++)
	{
		Array[i] = va_arg(v, int);
	}
	va_end(v);
}
Sort::Sort(const char* string)
{
	int count = 0;
	for (int i = 0; string[i]; ++i)
		if (string[i] == ',')count++;

	Array = new int[count + 1];
	Count = count + 1;
	int x = 0,index=0;

	for (int i = 0; string[i];)
	{
		if (string[i] == ',')
		{
			Array[index++] = x;
			x = 0;
			i++;
		}
		else
		{
			x = x * 10 + string[i] - '0';
			i++;
		}
		if (string[i] == '\0')
		{
			Array[index] = x;
			break;
		}
	}
}
void Sort::InsertSort(bool reverse)
{
	int i, key, j;

	if (reverse == false)
	{
		for (i = 1; i < Count; i++)
		{
			key = Array[i];
			j = i - 1;

			while (j >= 0 && Array[j] > key)
			{
				Array[j + 1] = Array[j];
				j = j - 1;
			}
			Array[j + 1] = key;
		}
	}
	else
	{
		for (i = 1; i < Count; i++)
		{
			key = Array[i];
			j = i - 1;

			while (j >= 0 && Array[j] < key)
			{
				Array[j + 1] = Array[j];
				j = j - 1;
			}
			Array[j + 1] = key;
		}
	}
}  

void Sort::QuickSort(bool reverse)
{
	if (reverse == false)
	{
		quickSort(Array, 0, Count - 1);
	}
	else
	{
		quickSort(Array, 0, Count - 1);
		for (int i = 0; i <= Count / 2; i++)
			swap(Array[i], Array[Count - i -1]);
	}
	
}
void Sort::BubbleSort(bool reverse)
{
	int st, dr;
	if (reverse == false)
	{
		st = 0;
		dr = Count-1;
		bool Done = false;
		while (!Done && dr > st)
		{
			Done = true;
			for (int i = st + 1; i <= dr; i++)
			{
				if (Array[i - 1] > Array[i])
				{
					swap(Array[i - 1], Array[i]);
					Done = false;
				}
			}
			dr--;
		}
	}
	else
	{
		st = 0;
		dr = Count - 1;
		bool Done = false;
		while (!Done && dr > st)
		{
			Done = true;
			for (int i = st + 1; i <= dr; i++)
			{
				if (Array[i - 1] < Array[i])
				{
					swap(Array[i - 1], Array[i]);
					Done = false;
				}
			}
			dr--;
		}
	}
}
void Sort::Print()
{
	for (int i = 0; i < Count; ++i)
		printf("%d ", Array[i]);
}
int  Sort::GetElementsCount()
{
	return Count;
}
int  Sort::GetElementFromIndex(int index)
{
	if (index < Count)
		return Array[index];
	else
		return 0;
}

