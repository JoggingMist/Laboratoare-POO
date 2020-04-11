#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;

bool isSeparator(char);
char ToLower(char);

typedef pair<string, int> Key_Value;

struct Compare {
    bool operator()(const Key_Value& x, const Key_Value& y)
    {
        if (x.second != y.second) {
            return x.second < y.second;
        }
        return x.first > y.first;
    }
};


char Sep[] = " !?,.";
int main()
{
    //Reading
    string Phrase;
    ifstream fin("inputFile.txt");
    getline(fin, Phrase);
    
    
 
    //Spliting
    string Words[20];
    int NumberOfWords = 0;
    
    string Word = "";
    for (char x : Phrase)
    {
        if (isSeparator(x))
        {
            if (!Word.empty())
            {
                Words[NumberOfWords++] = Word;
                Word = "";
            }
        }
        else
        {
            x = ToLower(x);
            Word += x;
        }
    }
    if (!Word.empty())Words[NumberOfWords++] = Word;


    //Using a map
    map<string,int> m;
    for (int index = 0; index < NumberOfWords; index++)
    {
        m[Words[index]]++;
    }


    /*for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << '\n';
    }*/
    
    //Using a priority queue

    priority_queue <Key_Value, vector<Key_Value>, Compare> pq(m.begin(), m.end());
    while (pq.empty() == false)
    {
        cout << pq.top().first << " ==> " << pq.top().second << "\n";
        pq.pop();
    }
    
}

bool isSeparator(char x)
{
    return strchr(Sep, x);
}

char ToLower(char x)
{
    if (x >= 'A' && x <= 'Z')return x + 32;
    return x;
}
