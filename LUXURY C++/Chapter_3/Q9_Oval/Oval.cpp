#include "Oval.h"

Oval::Oval() : Oval(1, 1)
{}

Oval::Oval(int width, int height) : _width(width), _height(height)
{}

int Oval::getWidth()
{
	return this->_width;
}

int Oval::getHeight()
{
	return this->_height;
}

void Oval::set(int w, int h)
{
	this->_width = w;
	this->_height = h;
}

void Oval::show()
{
	cout << "width : " << _width << ", " << "height : " << _height << endl;
}

Oval::~Oval()
{
	cout << "Oval 소멸 : width = " << _width << ", " << "height = " << _height << endl;;
}
