#include "pch.h"



istream& prompt(istream& ist)
{
	cout << "암호?";
	return ist;
}

int main()
{
	string password;
	while (true)
	{
		cin >> prompt >> password;

		if (password == "C++") {
			cout << "login success!!" << endl;
			break;
		}

		else
			cout << "login fail. try again!!" << endl;
	}
}
