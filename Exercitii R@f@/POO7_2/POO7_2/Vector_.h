#pragma once
template<class T>
class MyVector
{
	T* Array;
	int Array_Size;
	int Array_Count;

public:
	MyVector();
	~MyVector();
	void Push(T);
	T Pop();
	void Delete(int);
	void Insert(T, int);
	void Sort(bool (*fun)(const T, const T) = nullptr);
	const T& Get(int);
	void Set(T, int);
	int Count();
	int FirstIndexOf(T, bool(*fun)(const T, const T) = nullptr);
};

//########################################################################

template<class T>
T* Realocate(T* arr, int& Count, int& Size)
{
	Size = (Size << 1);
	T* arrayAux = new T[Size];
	//memcpy(arrayAux, arr, sizeof(T) * Count);
	for (int i = 0; i < Count; i++)
		arrayAux[i] = arr[i];

	delete[] arr;

	return arrayAux;
}

template<class T>
MyVector<T>::MyVector()
{
	Array_Size = 4;
	Array_Count = 0;
	Array = new T[Array_Size];
}

template<class T>
MyVector<T>::~MyVector()
{
	delete[] Array;
}

template<class T>
void MyVector<T>::Push(T x)
{
	if (Array_Count == Array_Size)
		Array=Realocate(Array, Array_Count, Array_Size);
	Array[Array_Count++] = x;
}

template<class T>
T MyVector<T>::Pop()
{
	return Array[Array_Count - 1];
}

template<class T>
void MyVector<T>::Delete(int index)
{
	for (int i = index; i < Array_Count - 1; i++)
		Array[i] = Array[i + 1];
	delete Array[Array_Count - 1];
	Array_Count--;
}

template<class T>
void MyVector<T>::Insert(T x, int index)
{
	if (Array_Count == Array_Size)
		Array=Realocate(Array, Array_Count, Array_Size);

	for (int i = Array_Count; i >= index; i--)
	{
		Array[i] = Array[i - 1];
	}

	Array[index] = x;
	Array_Count++;
}

template<class T>
bool isHigher(T a, T b)
{
	return (a > b);
}

template<class T>
void MyVector<T>::Sort(bool (*fun)(const T, const T))
{
	if (fun == nullptr) fun = isHigher;

	T aux;
	for (int i = 0; i < Array_Count - 1; i++)
		for (int j = i + 1; j < Array_Count; j++)
			if (fun(Array[i], Array[j]))
			{
				aux = Array[i];
				Array[i] = Array[j];
				Array[j] = aux;
			}
}

template<class T>
const T& MyVector<T>::Get(int index)
{
	return Array[index];
}

template<class T>
void MyVector<T>::Set(T x, int index)
{
	if (index < Array_Count)
	{
		Array[index] = x;
	}
}

template<class T>
int MyVector<T>::Count()
{
	return Array_Count;
}


template<class T>
bool isEqual(const T a, const T b)
{
	return (a == b);
}

template<class T>
int MyVector<T>::FirstIndexOf(T x, bool(*fun)(const T, const T))
{
	if (fun == nullptr) fun = isEqual;

	for (int index = 0; index < Array_Count; index++)
		if (fun(x, Array[index]))
			return index;
	return -1;
}