#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;

Add a;
Sub s;
Mul m;
Div d;


int main()
{
	string st;
	getline(cin, st);

	char* str = const_cast<char*>(st.c_str());
	const size_t size = strlen(str) + 1;
	char op;

	int arr[2] = {};
	int c = 0;

	char* p = strtok(str, " ");
	while (p != NULL)
	{
		if (*p == '+' || *p == '-' || *p == '*' || *p == '/')
		{
			op = *p;
			p = strtok(NULL, " ");
			continue;
		}

		arr[c++] = atoi(p);
		p = strtok(NULL, " ");
	}

	switch (op)
	{
	case '+':
		a.setValue(arr[0], arr[1]);
		cout << arr[0] << " + " << arr[1] << " = " <<  a.calculate() << endl;
		break;

	case '-':
		s.setValue(arr[0], arr[1]);
		cout << arr[0] << " - " << arr[1] << " = " << s.calculate() << endl;
		break;

	case '*':
		m.setValue(arr[0], arr[1]);
		cout << arr[0] << " * " << arr[1] << " = " << m.calculate() << endl;
		break;

	case '/':
		d.setValue(arr[0], arr[1]);
		cout << arr[0] << " / " << arr[1] << " = " << d.calculate() << endl;
		break;
	}
}

