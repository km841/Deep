#include <iostream>
#include <string>
#include "Circle.h"
using namespace std;

const Circle& operator++(Circle& c)
{
	c.radius += 1;
	return c;
}

Circle operator++(Circle& c, int n)
{
	Circle temp = c;
	c.radius++;

	return temp;
}

int main()
{
	Circle a(5), b(4);
  ++a;
  b = a++;
	a.show();
	b.show();
}
