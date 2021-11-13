#include "pch.h"

template <typename T>
T* concat(T* a, int sizea, T* b, int sizeb)
{
	T* ret = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++)
		ret[i] = a[i];

	for (int i = sizea; i < sizea + sizeb; i++)
		ret[i] = b[i - sizea];

	return ret;
}

int main()
{
	int x[] = { 1, 2, 3, 4, 5 };
	int y[] = { 6, 7, 8, 9, 10 };
	
	int* p = concat(x, 5, y, 5);
	for (int i = 0; i < 10; i++)
		cout << p[i] << ' ';

	delete p;
	cout << endl;
	char c1[] = { 'a', 'b', 'c' };
	char c2[] = { 'd', 'e', 'f' };
	char* c = concat(c1, 3, c2, 3);
	for (int i = 0; i < 6; i++)
		cout << c[i] << ' ';

	delete c;
}
