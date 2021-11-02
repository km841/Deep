#include "ArrayUtility2.h"

int* ArrayUtility2::concat(int s1[], int s2[], int size)
{
	const size_t total_size = size * 2;
	int* arr = new int[total_size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = s1[i];
		arr[i + size] = s2[i];
	}

	return arr;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize)
{
	bool flag = true;
	int* tempArray = new int[size];
	int arrCnt = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (s1[i] == s2[j]) flag = false;
		}

		if (flag)
		{
			tempArray[arrCnt++] = s1[i];
		}
		flag = true;
	}

	int* retArray = new int[arrCnt];
	for (int i = 0; i < arrCnt; i++)
	{
		retArray[i] = tempArray[i];
	}

	delete[] tempArray;
	retSize = arrCnt;

	return retArray;
}
