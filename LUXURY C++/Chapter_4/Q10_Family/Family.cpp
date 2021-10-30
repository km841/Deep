#include "Family.h"
#include "Person.h"

Family::Family(string name, int size)
{
	this->size = size;
	cout << name << "가족은 다음과 같이 " << this->size << "명 입니다." << endl;
	p = new Person[size];
}

void Family::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << (p + i)->getName() << '\t';
	}
}

void Family::setName(int n, string name)
{
	(p + n)->setName(name);
}

Family::~Family()
{
	if (p != nullptr)
	{
		delete[] p;
		p = nullptr;
	}
}
