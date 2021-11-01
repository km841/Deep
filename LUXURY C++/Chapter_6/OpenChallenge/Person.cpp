#include "Person.h"

Person::Person() : _name(), _num(0)
{
}

Person::~Person()
{
}

void Person::SetName(string name)
{
	this->_name = name;
}

string Person::GetName()
{
	return this->_name;
}

void Person::SetNum(int num)
{
	this->_num = num;
}

int Person::GetNum()
{
	return this->_num;
}
