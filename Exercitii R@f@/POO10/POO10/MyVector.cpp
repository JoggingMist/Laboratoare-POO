#include "MyVector.h"
#include <iostream>

using namespace std;

MyVector::MyVector()
{
	Count = 0;
}


bool MyVector::Add(int x)
{
	if (Count == 99)return 0;
	else {
		Array[Count++] = x;
	}
	return 1;
}

bool MyVector::Delete(int index)
{
	if (index > Count)return 0;
	else {
		for (int i = index; i < Count - 1; i++)
			Array[i] = Array[i + 1];
	}
	return 1;
}

void MyVector::Iterate(int(*fun) (int x))
{
	for (int i = 0; i < Count; i++)
	{
		Array[i] = fun(Array[i]);
	}
}



void MyVector::Filter(bool(*fun) (int x))
{
	for (int i = 0; i < Count; i++)
	{
		if (!fun(Array[i])) {
			this->Delete(i);
		}
	}
}

void MyVector::Print()
{
	for (int i = 0; i < Count; i++)
		cout << Array[i] << " ";
	cout << endl;
}