#pragma once
#include <iostream>
using namespace std;

class Color
{
	int colors[3];

public:
	Color(int red=0, int green=0, int blue=0);
	friend Color operator+ (Color& c1, Color& c2);
	friend bool operator== (Color& c1, Color& c2);

	int getRed();
	int getGreen();
	int getBlue();

	void show();
};

