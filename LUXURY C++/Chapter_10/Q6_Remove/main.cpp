#include "pch.h"

template <typename T>
T* remove(T* src, int sizeSrc, T* minus, int sizeMinus, int& retSize)
{
	T* temp = new T[sizeSrc];
	int tmpCnt = 0;
	bool flag = true;

	for (int i = 0; i < sizeSrc; i++)
	{
		for (int j = 0; j < sizeMinus; j++) 
			if (src[i] == minus[j]) {
				flag = false;
			}

		if (flag) {
			temp[tmpCnt++] = src[i];
		}

		flag = true;
	}

	retSize = tmpCnt;

	T* p = new T[tmpCnt];
	for (int i = 0; i < tmpCnt; i++)
		p[i] = temp[i];

	delete[] temp;
	return p;
}


int main()
{
	int src[] = { 1, 2, 3, 4, 5, 6, 7 };
	int m[] = { 3, 4, 5 };

	int retSize;

	int* p = remove(src, 7, m, 3, retSize);
	
	for (int i = 0; i < retSize; i++)
	{
		cout << p[i] << " ";
	}

	delete[] p;
}
