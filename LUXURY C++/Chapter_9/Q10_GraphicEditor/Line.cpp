#include "Line.h"



string Line::getShape()
{
	return "Line";
}

Line::~Line()
{
	if (next)
	{
		delete next;
		next = nullptr;
	}
}
