#pragma once
#include <iostream>
#include <string>
using namespace std;
class ArrayUtility2
{
public:
	static int* concat(int s1[], int s2[], int size);
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

