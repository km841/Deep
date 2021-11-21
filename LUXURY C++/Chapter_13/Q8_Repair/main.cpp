#include "pch.h"

int* copy(int* src, int size) {
	int* p = NULL;
	if (size < 0) throw 1;
	else if (size > 100) throw 2;
	
	p = new int[size];
	
	if (p == NULL) throw 3;
	else if (src == NULL) {
		delete[] p;
		throw 4;
	}

	else {
		for (int n = 0; n < size; n++) p[n] = src[n];
		return p;
	}
}


int main()
{
	int x[] = { 1, 2, 3 };
	int ret;
	int* p = nullptr;
	try {
		p = copy(x, 3);
		for (int i = 0; i < 3; i++) cout << p[i] << ' ';
		cout << endl;
	}

	catch (int n) {
		if (p != nullptr) delete[] p;
		if (n == 1) cout << "too small";
		if (n == 2) cout << "too big";
		if (n == 3) cout << "memory short";
		if (n == 4) cout << "NULL source";
		return 0;
	}
	
}
