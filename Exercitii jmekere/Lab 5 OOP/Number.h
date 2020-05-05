#pragma once
    

class Number
{

    char* s;
    int baza;
public:
    Number(const char* value, int base); // where base is between 2 and 16
    ~Number();

    //Number operator+(const Number&);

    //void SwitchBase(int newBase);
    //void Print();
    //int  GetDigitsCount(); // returns the number of digits for the current number
    //int  GetBase(); // returns the current base
};  