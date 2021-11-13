#include "Rect.h"



string Rect::getShape()
{
	return "Rect";
}

Rect::~Rect()
{
	if (this->next != nullptr)
	{
		delete this->next;
		this->next = nullptr;
	}
}
