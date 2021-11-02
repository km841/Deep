#pragma once
class MyVector
{
	int* mem;
	int size;

public:
	MyVector(int n=100, int val=0);
	~MyVector() { delete[] mem; }
};

