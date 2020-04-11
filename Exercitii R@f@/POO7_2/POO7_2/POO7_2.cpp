#include <iostream>
#include "Vector_.h"
#include "Number.h"
using namespace std;

void ex1()
{
	MyVector<char> v;
	v.Push('f');
	v.Push('e');
	v.Push('d');
	v.Push('c');
	v.Push('b');
	v.Push('a');
	v.Sort();

	for (int i = 0; i < v.Count(); i++)
		cout << v.Get(i) << " ";
}

int main()
{
	MyVector <Number> v;
	Number n1("FF", 16);
	Number n2("101", 2);
	Number n3;
	Number n4;
	v.Push(n1);
	v.Push(n2);
	v.Push(n3);
	v.Push(n4);
	v.Sort();

	return 0;
}
