#include "pch.h"



int main()
{
	cout << setw(15) << left << "Number";
	cout << setw(15) << left << "Square";
	cout << setw(15) << left << "Square Root";
	cout << endl;
	for (int i = 1; i < 10; i++)
	{
		cout << setfill('_') << setw(15) << left << i * 5;
		cout << setw(15) << left << (i * 5) * (i * 5);
		cout << setw(15) << left << sqrt(i * 5) << endl;
	}

}
