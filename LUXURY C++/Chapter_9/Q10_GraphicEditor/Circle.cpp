#include "Circle.h"



string Circle::getShape()
{
	return "Circle";
}

Circle::~Circle()
{
	if (this->next != nullptr)
	{
		delete this->next;
		this->next = nullptr;
	}
}
