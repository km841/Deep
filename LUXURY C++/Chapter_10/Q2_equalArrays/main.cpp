#include "pch.h"

template <typename T>
bool equalArrays(T x, T y, int n)
{
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (x[i] != y[i]) flag = false;
	}

	return flag;
}

int main()
{
	int x[] = { 1, 10, 100, 5, 4 };
	int y[] = { 1, 10, 100, 5, 4 };
	if (equalArrays(x, y, 5)) cout << "같다";
	else cout << "다르다";

	cout << endl;

	double a[] = { 1.0, 44.1, 3.3, 51.5, 99.0 };
	double b[] = { 1.0, 44.1, 3.3, 51.5, 99.0 };
	if (equalArrays(a, b, 5)) cout << "같다";
	else cout << "다르다";
}
