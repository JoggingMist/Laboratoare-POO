#include "Student.h"
#include <iostream>
Student::Student()
{
	Name = new char;
	MathGrade = 1;
	EnglishGrade = 1;
	HistoryGrade = 1;
}

char* Student::getName()
{
	return Name;
}
void Student::setName(const char* Input)
{
	strcpy(Name, Input);
}

float Student::getMathGrade()
{
	return MathGrade;
}
void Student::setMathGrade(float Input)
{
	MathGrade = (Input >= 1 && Input <= 10) ? Input : MathGrade;
}
float Student::getEnglishGrade()
{
	return EnglishGrade;
}
void Student::setEnglishGrade(float Input)
{
	EnglishGrade = (Input >= 1 && Input <= 10) ? Input : EnglishGrade;
}
float Student::getHistoryGrade()
{
	return HistoryGrade;
}
void Student::setHistoryGrade(float Input)
{
	HistoryGrade = (Input >= 1 && Input <= 10) ? Input : HistoryGrade;
}

float Student::average()
{
	return (MathGrade + EnglishGrade + HistoryGrade) / 3.f;
}
