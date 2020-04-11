#pragma once
class Sort
{
    int* Array;
    int Count;
public:
    Sort(int,int);//
    Sort(int* array, int count) : Count(count), Array(array) {};
    Sort(int,int*);
    Sort(int, ...);
    Sort(const char*);
    void InsertSort(bool reverse = false);
    void QuickSort(bool reverse = false);
    void BubbleSort(bool reverse = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
