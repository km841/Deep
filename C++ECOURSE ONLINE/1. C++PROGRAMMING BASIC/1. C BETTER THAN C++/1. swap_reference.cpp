#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void Swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int main()
{
	int n= 1, m = 2;
	cout << n << ", " << m << endl;

	Swap(n, m);
	cout << n << ", " << m << endl;
	return 0;
}
