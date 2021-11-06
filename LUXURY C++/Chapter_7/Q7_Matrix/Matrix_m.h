#pragma once
#include <iostream>
#include <string>
using namespace std;

class Matrix
{
	int mat[4];

public:
	Matrix(int a=0, int b=0, int c=0, int d=0);
	
	friend bool operator==(Matrix& m1, Matrix& m2);
	friend const Matrix& operator+= (Matrix& m1, Matrix& m2);
	friend Matrix operator+ (Matrix& m1, Matrix& m2);
	const Matrix& operator<< (int arr[4]);
	void operator>> (int arr[4]);

	void show();
};

