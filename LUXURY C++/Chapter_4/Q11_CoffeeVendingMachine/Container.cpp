#include "Container.h"

void Container::fill()
{
	this->size = 10;
}

void Container::consume()
{
	this->size -= 1;
}

int Container::getSize()
{
	return size;
}
