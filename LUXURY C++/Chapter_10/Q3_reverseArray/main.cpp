#include "pch.h"

template <typename T>
T& reverseArray(T* arr, int n) {

	int last = n-1;
	for (int i = 0; i < n / 2; i++)
	{
		T temp = arr[i];
		arr[i] = arr[last];
		arr[last] = temp;
		last--;
	}

	return *arr;
}

int main()
{
	int x[] = { 1, 10, 100, 5, 4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++) cout << x[i] << ' ';

	cout << endl;

	double y[] = { 1.3, 5.5, 61.1, 52.151, 166.5 };
	reverseArray(y, 5);
	for (int i = 0; i < 5; i++) cout << y[i] << ' ';

	cout << endl;

	char c[] = { 'a', 'b', 'c', 'd', 'e' };
	reverseArray(c, 5);
	for (int i = 0; i < 5; i++) cout << c[i] << ' ';

}
