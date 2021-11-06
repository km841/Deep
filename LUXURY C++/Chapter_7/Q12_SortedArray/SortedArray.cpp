#include "SortedArray.h"

void SortedArray::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (p[i] > p[j])
			{
				int tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}

SortedArray::SortedArray() : p(nullptr), size(0)
{
}

SortedArray::SortedArray(SortedArray& src)
{
	this->size = src.size;
	this->p = new int[size];

	for (int i = 0; i < this->size; i++)
		this->p[i] = src.p[i];

}

SortedArray::SortedArray(int p[], int size)
{
	this->size = size;
	this->p = new int[size];
	
	for (int i = 0; i < size; i++)
		this->p[i] = p[i];

}

SortedArray::~SortedArray()
{
	if (p != nullptr)
	{
		delete[] p;
		p = nullptr;
	}
}

SortedArray SortedArray::operator+(SortedArray& op2)
{
	SortedArray tmp;
	int cnt = 0;
	tmp.size = this->size + op2.size;
	tmp.p = new int[tmp.size];

	for (int i = 0; i < this->size; i++)
		tmp.p[cnt++] = this->p[i];
	
	for (int i = 0; i < op2.size; i++)
		tmp.p[cnt++] = op2.p[i];

	return tmp;
}

SortedArray& SortedArray::operator=(const SortedArray& op2)
{
	int* arr = new int[op2.size];

	for (int i = 0; i < op2.size; i++)
	{
		arr[i] = op2.p[i];
	}

	delete[] this->p;
	this->p = arr;
	this->size = op2.size;

	return *this;
}

void SortedArray::show()
{
	this->sort();
	cout << "배열 출력 : ";
	for (int i = 0; i < this->size; i++)
	{
		cout << this->p[i] << ' ';
	}
	cout << endl;
}
