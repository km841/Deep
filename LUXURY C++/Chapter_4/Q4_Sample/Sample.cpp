#include "Sample.h"

void Sample::read()
{
	for (int i = 0; i < size; i++)
	{
		cin >> p[i];
	}
}

void Sample::write()
{
	for (int i = 0; i < size; i++)
		cout << p[i] << " ";
	cout << endl;
}

int Sample::big()
{
	int b = -99999999;
	for (int i = 0; i < size; i++) {
		if (b < p[i]) b = p[i];
	}

	return b;
}

Sample::~Sample()
{
	if (p != nullptr) {
		delete[] p;
		p = nullptr;
	}

}
