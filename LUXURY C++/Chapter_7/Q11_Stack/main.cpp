#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;



int main()
{
	Stack stack;
	stack << 3 << 5 << 10;
	while (true)
	{
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}

	cout << endl;
}
