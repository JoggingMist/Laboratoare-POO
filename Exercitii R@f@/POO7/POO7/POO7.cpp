#include <iostream>

using namespace std;

float operator"" _Kelvin(unsigned long long x)
{
    return x - 273.15f;
}

float operator"" _Fahrenheit(unsigned long long x)
{
    return (x - 32) / 1.8f;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << a << endl;
    cout << b;
}