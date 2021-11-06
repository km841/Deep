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

int main()
{
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
}
