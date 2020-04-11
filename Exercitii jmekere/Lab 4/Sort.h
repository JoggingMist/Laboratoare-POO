#pragma once
#define _CRT_SECURE_NO_WARNINGS
class Sort
{
    int* Array;
    int  nr;
public:
    Sort(int, int);
    Sort(int* array, int count) : nr(count), Array(array) {};
   /* Sort(int*, int);*/
    Sort(int count, ...);
    Sort(char* s, int count);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
