#include "pch.h"

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <typename T>
T bigger(T a, T b)
{
	return a > b ? a : b;
}

Circle bigger(Circle a, Circle b)
{
	return a.getRadius() > b.getRadius() ? a.getRadius() : b.getRadius();
}


int main()
{
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}
