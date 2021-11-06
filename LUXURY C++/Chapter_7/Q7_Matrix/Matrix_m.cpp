#include "Matrix.h"

Matrix::Matrix(int a, int b, int c, int d)
{
	mat[0] = a;
	mat[1] = b;
	mat[2] = c;
	mat[3] = d;
}


const Matrix& Matrix::operator<<(int arr[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->mat[i] = arr[i];
	}

	return *this;
}

void Matrix::operator>>(int arr[4])
{

	for (int i = 0; i < 4; i++)
	{
		arr[i] = this->mat[i];
	}
}

void Matrix::show()
{
	cout << "Matrix = { " << this->mat[0];
	cout << " " << this->mat[1];
	cout << " " << this->mat[2];
	cout << " " << this->mat[3];
	cout << " }" << endl;
}
