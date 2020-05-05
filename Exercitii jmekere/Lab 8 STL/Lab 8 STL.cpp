#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <fstream>
#include <utility>

using namespace std;

ifstream inputFile("Apple.txt");

typedef pair<string, int> Key_Value;

class Comparare
{
public:
	bool operator()(const Key_Value& x1, const Key_Value& x2)
	{
		if (x1.second != x2.second)
		{
			return x1.second < x2.second;
		}
		return x1.first > x2.first;
	}
};

void lowerCase(string &s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
}

int main()
{
	string Apple;
	getline(inputFile, Apple);

	string words[20];

	string word = "";

	int numberOfWords = 0;
	for (int x=0; x < Apple.size();  x++)
	{
		if (Apple[x] == ' ' || Apple[x] == '.' || Apple[x] == ',' || Apple[x] == '!' || Apple[x] == '?')
		{
			if (word != " " && word != "")
			{
				lowerCase(word);
				words[numberOfWords++] = word;
			}
			word = "";
		}
		else
		{
			word = word + Apple[x];
		}
	}

	map<string, int> Mapa;
	for (int i = 0; i < numberOfWords; i++)
	{
		Mapa[words[i]]++;
	}

	map<string, int>::iterator it;
	/*for (it = Mapa.begin(); it != Mapa.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}*/

	priority_queue<Key_Value, vector<Key_Value>, Comparare> coada(Mapa.begin(), Mapa.end());
	while (!coada.empty())
	{
		cout << coada.top().first << "-->" << coada.top().second << endl;
		coada.pop();
	}
}


