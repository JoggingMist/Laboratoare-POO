#include <iostream>
#include "vectorTemplate.h"

using namespace std;

int main()
{
	VectorT<int> v;
	v.push(45);
	v.push(4);
	v.push(5);
	v.push(13);
	v.push(22);
	v.push(11);
	
	for (int i = 0; i < v.count(); i++)
	{
		cout << v.get(i) << ' ';
	}
	cout << endl;

	cout << v.firstIndexOf(5) << endl;

	v.insert(19, 1);
	v.insert(28, 10);

	for (int i = 0; i < v.count(); i++)
	{
		cout << v.get(i) << ' ';
	}
	cout << endl;
	v.sort();
	for (int i = 0; i < v.count(); i++)
	{
		cout << v.get(i) << ' ';
	}
	cout << endl;

	//stergerea merge
	//v.remove(2);
	//for (int i = 0; i < v.count(); i++)
	//{
	//	cout << v.get(i) << ' ';
	//}
	//cout << endl;

	
}