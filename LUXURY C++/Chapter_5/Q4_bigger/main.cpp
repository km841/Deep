#include <iostream>
#include <string>
using namespace std;

bool bigger(int a, int b, int& big)
{
	if (a == b) return true;
	else {
		big = a > b ? a : b;
		return false;
	}
}


int main()
{
	int b = 0;
	bigger(3, 5, b);
	cout << b << endl;
}

