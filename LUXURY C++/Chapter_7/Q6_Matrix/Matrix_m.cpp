#include "Matrix.h"

Matrix::Matrix(int a, int b, int c, int d)
{
	mat[0] = a;
	mat[1] = b;
	mat[2] = c;
	mat[3] = d;
}

Matrix Matrix::operator+(Matrix& m)
{
	Matrix temp;
	for (int i = 0; i < 4; i++)
	{
		temp.mat[i] = this->mat[i] + m.mat[i];
	}

	return temp;
}

const Matrix& Matrix::operator+=(Matrix& m)
{
	for (int i = 0; i < 4; i++)
	{
		this->mat[i] += m.mat[i];
	}
	return *this;
}

bool Matrix::operator==(Matrix& m)
{
	bool flag = true;
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i] != m.mat[i]) flag = false;
	}
	
	if (flag) return true;
	else return false;
}

void Matrix::show()
{
	cout << "Matrix = { " << this->mat[0];
	cout << " " << this->mat[1];
	cout << " " << this->mat[2];
	cout << " " << this->mat[3];
	cout << " }" << endl;
}
