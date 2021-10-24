#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

// ascii 97~122 : a~z

int main()
{
	map<char, int> cim;
	char arr[1000];
	int total = 0;
	cin.getline(arr, 1000, ';');
	cout << endl;

	const size_t size = strlen(arr);

	for (int i = 97; i <= 122; i++)
	{
		cim[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		if ((arr[i] >= 97) && (arr[i] <= 122))
		{
			cim[arr[i]] += 1;
			total += 1;
		}
	}

	cout << "총 알파벳 수 : " << total << endl << endl;

	for (const auto& i : cim)
	{
		cout << i.first << " (" << i.second << ")   : ";

		for (int j = 0; j < i.second; j++)
		{
			cout << "*";
		}
		cout << endl;

	}
}

