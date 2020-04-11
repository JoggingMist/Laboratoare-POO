#include <iostream>
#include "Sort.h"
using namespace std;

void exemple1()//
{
    Sort s(10,20);
    s.BubbleSort();
    s.Print();
}

void exemple2()
{
    Sort s = { new int[3]{ 3,1,2 } , 3 };
    s.BubbleSort();
    s.Print();                  
}

void exemple3()
{
    int v[] = { 3,2,1,5,4 };
    Sort s(5, v);
    s.BubbleSort();
    s.Print();
}

void exemple4()
{
    Sort s(5, 2, 3, 1, 4, 5);
    s.BubbleSort();
    s.Print();
}

void exemple5()
{
    Sort s("1,2,10,3");
    s.BubbleSort(true);
    s.Print();
}

int main()
{
    //exemple1();
    exemple2();
    //exemple3();
    //exemple4();
    //exemple5();

    return 0;
}

