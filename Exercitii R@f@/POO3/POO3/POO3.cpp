#include <iostream>
#include "Math.h"
#include "Canvas.h"
using namespace std;

int main()
{
    //Math obj;
    //cout << Math::Add("Ana are mere si ", "Gigel are pere");
    
    Canvas c(200,200);
    c.DrawCircle(10, 10, 3, 'P');
    //c.DrawElipse(75, 75, 25,50,'0');
    //c.DrawRect(75 - 30, 75 - 30, 75 + 30, 75 + 30, '$');
    //c.DrawLine(30,30,50,28,'X');
    //c.SetPoint(5, 5, '^');
    //c.FillRect(0, 0, 20, 20, '%');
    //c.Clear();
    c.Print();
}
