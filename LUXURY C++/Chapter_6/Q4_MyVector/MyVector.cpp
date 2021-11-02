#include "MyVector.h"

MyVector::MyVector(int n, int val)
{
	mem = new int[n];
	size = n;
	for (int i = 0; i < n; i++) mem[i] = val;
}
