#include "pch.h"

int* concat(int a[], int sizea, int b[], int sizeb) {
	if (a == NULL || b == NULL)
		throw 1;

	if (sizea < 0 || sizeb < 0)
		throw 2;

	int* p = new int[sizea + sizeb];
	if (p == nullptr) throw 3;
	for (int i = 0; i < sizea; i++) {
		p[i] = a[i];
	}

	for (int i = sizea; i < sizea + sizeb; i++) {
		p[i] = b[i-sizea];
	}

	return p;
}

int main()
{
	int x[] = { 1, 2, 3, 4, 5 };
	int y[] = { 10, 20 ,30 ,40 };
	
	try {
		int* p = concat(x, 5, y, 4);
		for (int n = 0; n < 9; n++) cout << p[n] << ' ';
		cout << endl;
		delete[] p;
	}

	catch (int failCode) {
		cout << "오류 코드 : " << failCode << endl;
	}
	
}
