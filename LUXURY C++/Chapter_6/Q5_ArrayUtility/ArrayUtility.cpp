#include "ArrayUtility.h"

void ArrayUtility::intToDouble(int source[], double dest[], int size)
{
	for (int i = 0; i < size; i++)
	{
		dest[i] = static_cast<double>(source[i]);
	}
}

void ArrayUtility::doubleToInt(double source[], int dest[], int size)
{
	for (int i = 0; i < size; i++)
	{
		dest[i] = static_cast<int>(source[i]);
	}
}
