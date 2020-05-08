#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MyFunction(int aa)
{
	int a, b, c;
	a = b = c = 10;
	auto f = [&](int x, int y) {return x + y + a + b + c + aa; };
	decltype(f) f2 = f;
	printf("%d\n", f(10,20));
	aa = 2000;
	printf("%d", f2(1000, 20));
}

void ex1()
{
	vector<string> array;
	array.push_back("I");
	array.push_back("bought");
	array.push_back("an");
	array.push_back("apple");
	array.push_back("Then");
	array.push_back("i");
	array.push_back("eat");
	array.push_back("an");
	array.push_back("apple");
	auto f = [&array]
	{
		for (int i = 0; i < array.size() - 1; i++)
			for (int j = i + 1; j < array.size(); j++)
			{
				if (array[i].size() < array[j].size())
					swap(array[i], array[j]);
			}
	};
	f();
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << endl;
}

void ex2()
{
	int ceva[10] = { 1, 15, 26, 29, 39, 48, 52, 27, 14, 10};
	auto f = [ceva](int max)
	{
		for (int i = 1; i< 10; i++)
			if (ceva[i] > max)
				max = ceva[i];
		cout << max;
	};
	f(1);
}

void ex3()
{
	auto lambda = [](int x) {return x * 5; };
	class MyVector 
	{
		int* array;
		int counter;
		int size;
	public:
		MyVector()
		{
			size = 2;
			array = new int[size];
			counter = 0;
		};
		bool Add(int value)
		{
			if (counter == size)
			{
				int* newArray = new int[size];
				for (int i = 0; i < size; i++)
					newArray[i] = array[i];
				array = new int[++size];
				for (int i = 0; i < size - 1; i++)
					array[i] = newArray[i];
				array[size - 1] = value;
				delete[] newArray;
				counter++;
			}
			else
			{
				array[counter++] = value;
			}
			return true;
			
		}; 
		
		bool Delete(int index)
		{
			int* newArray = new int[size];
			for (int i = 0; i < size; i++)
				newArray[i] = array[i];
			for (int i = index; i < size; i++)
			{
				newArray[i] = newArray[i + 1];
			}
			array = new int[--size];
			for (int i = 0; i < size; i++)
				array[i] = newArray[i];
			delete[] newArray;
			counter--;
			return true;
		}; // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.
		
		void Print()
		{
			for (int i = 0; i < size; i++)
				cout << array[i] << endl;
			cout << endl;
		}

		
		void Iterate(int(*fun)(int x))
		{
			for (int i = 0; i < size; i++)
			{
				array[i] = fun(array[i]);
			}
		}

		void Filter(bool(*fun)(int x))
		{
			for (int i = 0; i < size; i++)
			{
				if (fun(array[i]))
					Delete(i);
			}
		}

	};

	MyVector vectoras;
	vectoras.Add(1);
	vectoras.Add(2);
	vectoras.Add(3);
	vectoras.Add(4);
	vectoras.Add(5);
	vectoras.Iterate([](int x) {if (x % 2 == 0) return 80; else return 0; });
	vectoras.Print();
	vectoras.Filter([](int x) {if (x % 2 == 0) return true; else return false; });
	vectoras.Print();
}



void main()
{
	ex1();
	cout << endl;
	ex2();
	cout << endl;
	ex3();

}