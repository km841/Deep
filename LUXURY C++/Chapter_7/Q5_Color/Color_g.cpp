#include "Color.h"

Color::Color(int red, int green, int blue)
{
	colors[0] = red;
	colors[1] = green;
	colors[2] = blue;

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
