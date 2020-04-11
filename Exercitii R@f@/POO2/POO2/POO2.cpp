#include <iostream>
#include "Student.h"
#include "NumberList.h"
using namespace std;

int compareName(Student s1, Student s2)
{
    if (strcmp(s1.getName(), s2.getName()) == 0)
        return 0;
    else if (strcmp(s1.getName(), s2.getName()) < 0)
        return -1;
    else 
        return 1;
}

int compareAverage(Student s1, Student s2)
{
    if (s1.average() == s2.average())
        return 0;
    else if (s1.average() < s2.average())
        return -1;
    else
        return 1;
}

int compareMathGrade(Student s1, Student s2)
{
    if (s1.getMathGrade() == s2.getMathGrade())
        return 0;
    else if (s1.getMathGrade() < s2.getMathGrade())
        return -1;
    else
        return 1;
}

int compareEnglishGrade(Student s1, Student s2)
{
    if (s1.getEnglishGrade() == s2.getEnglishGrade())
        return 0;
    else if (s1.getEnglishGrade() < s2.getEnglishGrade())
        return -1;
    else
        return 1;
}

int compareHistoryGrade(Student s1, Student s2)
{
    if (s1.getHistoryGrade() == s2.getHistoryGrade())
        return 0;
    else if (s1.getHistoryGrade() < s2.getHistoryGrade())
        return -1;
    else
        return 1;
}

int main()
{
    
    Student s1,s2;
    s1.setName("Ion");
    s1.setMathGrade(4);
    s1.setEnglishGrade(10);
    s1.setHistoryGrade(5);

    s1.setName("John");
    s1.setMathGrade(7);
    s1.setEnglishGrade(10);
    s1.setHistoryGrade(8);

    cout << compareAverage(s1, s2);
    
}
