#include <iostream>
//#pragma warning(disable:4996)

class Number
{
    char* numar;
    int decimal = 0; //asta e numarul convertit intr o baza comuna
    int baza;
public:

    Number(const char* value, int base); // where base is between 2 and 16
    //~Number();

    /*Number operator+(Number&);*/

   /* void SwitchBase(int newBase);*/
    //void Print();
    //int  GetDigitsCount(); // returns the number of digits for the current number
    //int  GetBase(); // returns the current base
};