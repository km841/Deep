#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

namespace Util {
	template <typename T>
	void Swap(T& x, T& y) {
		T temp = x;
		x = y;
		y = temp;
	}
}

int main()
{
	int n= 1, m = 2;
	double i = 1.1, j = 2.2;
	cout << n << ", " << m << endl;

	std::swap(n, m);
	cout << n << ", " << m << endl;

	cout << i << ", " << j << endl;

	std::swap(i, j);
	cout << i << ", " << j << endl;


	return 0;
}
