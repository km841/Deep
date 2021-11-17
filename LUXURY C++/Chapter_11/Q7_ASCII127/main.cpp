#include "pch.h"

int main()
{
	for (int i = 0; i < 4; i++) {
		cout << setw(10) << left << "dec";
		cout << setw(10) << left << "hexa";
		cout << setw(10) << left << "char";
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << setw(10) << left << "---";
		cout << setw(10) << left << "----";
		cout << setw(10) << left << "----";
	}
	cout << endl;

	for (int i = 0; i < 128; i+=4)
	{
		for (int j = 0; j < 4; j++) {
			cout << setw(10) << left << dec << i + j;
			cout << setw(10) << left << hex << i + j;
			if (isprint((char)(i+j)))
				cout << setw(10) << left << (char)(i + j);
			else
				cout << setw(10) << left << '.';
		}
		cout << endl;
	}
}
