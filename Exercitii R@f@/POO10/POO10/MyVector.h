#pragma once
class MyVector
{
	int Array[100];
	int Count;
public:
	MyVector();
	bool Add(int);
	bool Delete(int);
	void Iterate(int(*fun) (int x));
	void Filter(bool(*fun) (int x));
	void Print();
};

