#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void Swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

int main()
{
	int n= 1, m = 2;
	double i = 1.1, j = 2.2;
	cout << n << ", " << m << endl;

	Swap(n, m);
	cout << n << ", " << m << endl;

	cout << i << ", " << j << endl;

	Swap(i, j);
	cout << i << ", " << j << endl;


	return 0;
}
