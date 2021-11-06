#include "Color.h"

Color::Color(int red, int green, int blue)
{
	colors[0] = red;
	colors[1] = green;
	colors[2] = blue;

}

Color Color::operator+(Color& c)
{
	Color tmp;
	int sum = 0;

	for (int i = 0; i < 3; i++) {

		sum = this->colors[i] + c.colors[i];
		if (sum > 255) sum = 255;
		tmp.colors[i] = sum;
	}

	return tmp;
}

bool Color::operator==(Color& c)
{
	return this->getRed() == c.getRed() &&
		this->getGreen() == c.getGreen() &&
		this->getBlue() == c.getBlue();
}

int Color::getRed()
{
	return colors[0];
}

int Color::getGreen()
{
	return colors[1];
}

int Color::getBlue()
{
	return colors[2];
}

void Color::show()
{
	cout << getRed() << ' ' << getGreen() << ' ' << getBlue() << endl;
}
