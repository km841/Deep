#include <iostream>
#include <string>
#include "Color.h"
using namespace std;

Color operator+ (Color& c1, Color& c2)
{
	Color tmp;
	int sum;

	for (int i = 0; i < 3; i++)
	{
		sum = c1.colors[i] + c2.colors[i];
		if (sum > 255) sum = 255;
		tmp.colors[i] = sum;
	}

	return tmp;
}
bool operator== (Color& c1, Color& c2)
{
	return (c1.colors[0] == c2.colors[0] &&
		c1.colors[1] == c2.colors[1] &&
		c1.colors[2] == c2.colors[2]);
}

int main()
{
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}
