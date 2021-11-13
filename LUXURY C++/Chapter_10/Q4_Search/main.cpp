#include "pch.h"

template <typename T>
bool search(T val, T* arr, int n)
{
	bool flag = false;
	for (int i = 0; i < n; i++)
		if (val == arr[i]) flag = true;

	return flag;
}

int main()
{
	int x[] = { 1, 10, 100, 5, 4 };
	if (search(100, x, 5)) cout << "100이 배열 x에 포함되어 있다.";
	else cout << "100이 배열 x에 포함되어 있지 않다.";

	cout << endl;

	double y[] = { 4.0, 4.4, 501.1, 11.111, 0.015 };
	if (search(11.111, y, 5)) cout << "11.111이 배열 y에 포함되어 있다.";
	else cout << "11.111이 배열 y에 포함되어 있지 않다.";
}
