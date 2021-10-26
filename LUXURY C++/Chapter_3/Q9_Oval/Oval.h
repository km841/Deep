#pragma once
#include <iostream>
using namespace std;

class Oval
{
private:
	int _width, _height;

public:

	Oval();
	Oval(int width, int height);
	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();



	~Oval();
};

