#pragma once
#include <iostream>
#include <string>
using namespace std;

class Matrix
{
	int mat[4];

public:
	Matrix(int a=0, int b=0, int c=0, int d=0);
	Matrix operator+ (Matrix& m);
	const Matrix& operator+= (Matrix& m);
	bool operator== (Matrix& m);

	void show();
};

