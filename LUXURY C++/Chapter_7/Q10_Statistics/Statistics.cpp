#include "Statistics.h"

Statistics::Statistics() : stat(new int[3]), size(0), capacity(3)
{
}

void Statistics::realloc_size()
{
	if (size == capacity)
	{
		int re_size = this->capacity * 1.5;
		int* re_stat = new int[re_size];

		for (int i = 0; i < capacity; i++)
		{
			re_stat[i] = stat[i];
		}

		delete[] stat;
		stat = re_stat;
		capacity = re_size;

		cout << "메모리가 " << capacity << "로 재할당되었습니다." << endl;
	}
}

bool Statistics::operator!()
{
	return size;
}

Statistics& Statistics::operator<<(int n)
{
	this->realloc_size();
	stat[size++] = n;

	return *this;
}

int& Statistics::operator>>(int& n)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += stat[i];
	}

	n = sum / size;
	return n;
}

void Statistics::operator~()
{
	for (int i = 0; i < size; i++)
		cout << stat[i] << ' ';
	cout << endl;
}

Statistics::~Statistics()
{
	if (stat != nullptr)
	{
		delete[] stat;
		stat = nullptr;
	}
}
