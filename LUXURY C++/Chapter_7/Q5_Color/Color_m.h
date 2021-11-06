#pragma once
#include <iostream>
using namespace std;

class Color
{
	int colors[3];

public:
	Color(int red=0, int green=0, int blue=0);
	Color operator+ (Color& c);
	bool operator== (Color& c);

	int getRed();
	int getGreen();
	int getBlue();

	void show();
};

