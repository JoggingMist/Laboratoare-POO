#pragma once
#include <utility>

using namespace std;
template<class Key, class Value>
struct tuplă
{
	Key a;
	Value b;
	int index;
};

template <class Key, class Value>
class Iterator
{
	pair<Key, Value>* a;
	int size;
	int iterator;

public:
	Iterator(pair<Key, Value>* a, int size, int i = 0) : a(a), size(size), iterator(i) {}

	void operator++()
	{
		iterator++;
	}

	void operator++(int)
	{
		iterator++;
	}

	bool operator!=(Iterator _other)
	{
		return iterator != _other.iterator;
	}

	tuplă<Key, Value> operator*()
	{
		return { a[iterator].first, a[iterator].second ,iterator };
	}

};

template<class T1, class T2>
class Map
{
public:
	pair<T1, T2>* obiect;
	Map() :index(0) { obiect = new pair<T1, T2>[10]; };
	int index;
	//void Set(T1 , T2);
	T2& operator[](T1);
	bool Get(const T1&, T2&);
	int Count();
	void Clear();
};

template<class T1, class T2>
bool Map<typename T1, typename T2>::Get(const T1& cheie, T2& valoare)
{
	for (int i = 0; i < index; i++)
	{
		if (obiect[i].first == cheie)
		{
			valoare = obiect[i].second;
			return true;
		}
	}
	return false;
}

template<class T1, class T2>
int Map<typename T1, typename T2>::Count()
{
	return index;
}

template<class T1, class T2>
void Map<typename T1, typename T2>::Clear()
{
	delete[] obiect;
	obiect = new pair[10];
}

template<class T1, class T2>
T2& Map<typename T1, typename T2>::operator[](T1 cheie)
{
	for (int i = 0; i < index; i++)
	{
		if (obiect[i].first == cheie)
			return obiect[i].second;
	}
	obiect[index].first = cheie;
	return obiect[index++].second;
	
}
