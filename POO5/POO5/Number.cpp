#include <iostream>
#include "Number.h"
#include <cmath>
#include <string>

using namespace std;




Number::Number(const char* value, int base)
{
	baza = base;
	int length = strlen(value);
														
	numar = new char[length];							  
		
	//am pus sirul primit in variabila privata
	for (int i = 0; i < length; i++)								 
	{													  
		numar[i] = value[i];							  
	}													  
														  
	numar[length] = '\0';								  
	
	//convertire sir primit in baza 10 indiferent de baza
	for (int i = 0; i < length; i++)					  
	{													  
		int cifra = numar[i] - '0';						  
		int litera = numar[i] - 55;//indexare litere						  
														  
		int p = pow(baza, length - i - 1);				  
		if ( cifra < 10	)								  
		{												  
			decimal = cifra * p + decimal;	 														  
		}		
		else
		{
			decimal = litera * p + decimal;
		}
		
	}
	cout << decimal;
	//verificare convertire 
	//cout << decimal;
}		


void Number::SwitchBase(int newBase)
{
	//nu ar functiona cum trebuie pentru ca trebuie trecut variabila decimal in sir de caractere
	//deci trebuie sa facem pentru orice valoare convertirea in sir
	/*if (newBase == 10)
		return;*/
	
	
	int memAlloc = 0;
	int tmp = decimal;
	
	//cout <<endl<<decimal;

	//determinare de memorie pentru alocare pentru noul sir
	while (tmp!=0)
	{
		tmp /= newBase;
		memAlloc++;
	}

	//alocare memorie noul sir

	numar = new char[memAlloc];
	//[ 2, 3, 4, , , , , , , ]
	//
	//
	tmp = decimal;
	int cifraCurenta;
	numar[memAlloc] = '\0';
	while (tmp)
	{
		cifraCurenta = tmp % newBase;
		if (cifraCurenta < 10)
		{
			numar[memAlloc - 1] = cifraCurenta + '0';//asociere cifra din decimal
			tmp /= newBase;
			memAlloc--;
		}
		else
		{
			numar[memAlloc - 1] = cifraCurenta + 55;//asociere litera din decimal
			tmp /= newBase;
			memAlloc--;
		}
	}

}

//creca stim cu totii ce face asta
int Number::GetBase()
{
	return baza;
}

//afiseaza un sir de caractere
void Number::Print()
{
	cout << endl;
	for (int i = 0; i < strlen(numar); i++)
	{
		cout << numar[i];
	}
	cout << endl;
}

//Number::~Number()
//{
//	delete[] numar;
//}


Number Number::operator+(Number& n)
{
	int b1 = baza;
	int val1 = decimal;
	int b2 = n.baza;
	int val2 = n.decimal;

	/*
		bool Number::operator<(Number& n)
		{
		int val1 = decimal;
		int val2 = n.decimal;
		return val1<val2;
		}
		bool Number::operator>=(Number& n)
		{
			return !operator<(n);
		}
	*/

	int newBase = (b1 > b2) ? b1 : b2;

	char* rezultat;

	//alocare memorie rezutat
	int tmp = val1 + val2;
	int k = 0;
	while (tmp)
	{
		k++;
		tmp /= 10;
	}
	rezultat = new char[k];

	_itoa(val1 + val2, rezultat, 10);

	Number x(rezultat, 10);

	x.SwitchBase(newBase);

	return x;
}


int Number::GetDigitsCount()
{
	return strlen(numar);
}