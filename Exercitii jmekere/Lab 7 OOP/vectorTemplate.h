#pragma once


template<class T>
class VectorT
{
	T* array;
	int size;
	int counter;
public:
	VectorT();
	void push(T);
	T pop();
	void remove(int);
	void insert(T, int);
	void sort(bool(*fun)(const T, const T) = nullptr);
	const T& get(int);
	void set(T,int);
	int count();
	int firstIndexOf(T, bool(*fun)(const T, const T) = nullptr);
};

template<class T>
VectorT<T>::VectorT()
{
	counter = 0;
	size = 4;
	array = new T[size];
}

template<class T>
T* realloc(T* array, int& size, int& counter)
{
	size = size << 1;
	T* tmp;
	tmp = new T[size];

	for (int i = 0; i < counter; i++)
	{
		tmp[i] = array[i];
	}

	delete[] array;
	
	return tmp;
}

template<class T>
void VectorT<T>::push(T value)
{
	if (counter == size)
		realloc(array, size);
	array[counter++] = value;
}

template<class T>
T VectorT<T>::pop()
{
	return array[counter - 1];
}

template<class T>
void VectorT<T>::remove(int index)
{
	for (int i = index; i < size; i++)
		array[i] = array[i + 1];
	counter--;
}

template<class T>
void VectorT<T>::insert(T value, int index)
{
	if (counter == size)
		realloc(array, size, counter);
	else
		if (index > counter)
		{
			std::cout << "-Eroare insertie-\nIndexul este prea mare. Indexul maxim este: " << counter << std::endl;
			return;
		}

	for (int i = counter; i >= index; i--)
	{
		array[i] = array[i - 1];
	}
	array[index] = value;
	counter++;
}

template<class T>
bool isHigher(const T a, const T b)
{
	return (a > b);
}

template<class T>
 void VectorT<T>::sort(bool(*fun)(const T, const T))
{
	 if (fun == nullptr)
		 fun = isHigher;
	 T aux;
	 for (int i = 0; i < counter; i++)
	 {
		 for (int j = i + 1; j < counter; j++)
			 if (fun(array[i], array[j]))
			 {
				 aux = array[i];
				 array[i] = array[j];
				 array[j] = aux;
			 }

	 }
}

 template<class T>
 const T& VectorT<T>::get(int index)
 {
	 return array[index];
 }

 template<class T>
 void VectorT<T>::set(T x, int index)
 {
	 if (index < counter)
	 {
		 array[index] = x;
	 }
 }

 
 template<class T>
 int VectorT<T>::count()
 {
	 return counter;
 }

 template<class T>
 bool isEqual(T a, T b)
 {
	 return a == b;
 }

 template<class T>
 int VectorT<T>::firstIndexOf(T value, bool(*fun)(const T, const T))
 {
	 if (fun == nullptr)
		 fun = isEqual;
	 for (int i = 0; i < counter; i++)
	 {
		 if (isEqual(array[i], value))
			 return i;
	 }
	 return -1;
 }
	






