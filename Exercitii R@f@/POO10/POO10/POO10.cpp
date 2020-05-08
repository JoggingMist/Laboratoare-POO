#include <iostream>
#include <vector>
#include <algorithm>
#include "MyVector.h"
using namespace std;

void Task1()
{
    vector<string> V = { "are" , "arici" , "mos" , "mosor" , "john" };
    sort(V.begin(), V.end(), [](string s1, string s2) ->bool 
    { 
        if (s1.length() > s2.length())return 1;
        else if (s1.length() < s2.length())return 0;
        else return s1 < s2;
    });
    for (auto x : V) {
        cout << x << endl;
    }
}

void Task2()
{
    auto max = [](initializer_list<int> list) ->int {
        int maximum = 0;
        for (auto x : list) {
            maximum = (x > maximum) ? x : maximum;
        }
        return maximum;
    };

    initializer_list<int> list = { 4,5,6,7,1,100,5 };
    cout << max(list) << endl;
}

void Task3()
{
    MyVector v;
    v.Add(1);
    v.Add(2);
    v.Add(3);
    v.Add(4);
    v.Add(5);
    v.Iterate([](int x) ->int {  if (x % 2 == 1)return 666;  else return x; } );
    v.Print();
}

int main()
{
    Task1();

    return 0;
}

