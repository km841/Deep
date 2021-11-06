#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

Matrix operator+ (Matrix& m1, Matrix& m2)
{
	Matrix temp;

	for (int i = 0; i < 4; i++)
	{
		temp.mat[i] = m1.mat[i] + m2.mat[i];
	}
	return temp;

}

const Matrix& operator+= (Matrix& m1, Matrix& m2)
{
	for (int i = 0; i < 4; i++)
	{
		m1.mat[i] += m2.mat[i];
	}

	return m1;
}

bool operator==(Matrix& m1, Matrix& m2)
{
	bool flag = true;

	for (int i = 0; i < 4; i++)
	{
		if (m1.mat[i] != m2.mat[i]) flag = false;
	}

	if (flag) return true;
	else return false;
}

const Matrix& operator<< (Matrix& m, int arr[4])
{
	for (int i = 0; i < 4; i++)
	{
		m.mat[i] = arr[i];
	}
	return m;
}

void operator>> (Matrix& m, int arr[4])
{
	for (int i = 0; i < 4; i++)
	{
		arr[i] = m.mat[i];
	}
}

int main()
{
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1, 2, 3, 4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}
