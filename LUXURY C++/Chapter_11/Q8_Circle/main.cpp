#include "pch.h"

class Circle
{
	string name;
	int radius;

public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius;
		this->name = name;
	}

	friend istream& operator>> (istream& ist, Circle& c);
	friend ostream& operator<< (ostream& ost, Circle& c);
};

istream& operator>> (istream& ist, Circle& c) {
	cout << "반지름 >> ";
	ist >> c.radius;
	ist.ignore();

	cout << "이름 >> ";
	ist >> c.name;
	ist.ignore();
	return ist;
}

ostream& operator<< (ostream& ost, Circle& c) {
	ost << "(" << "반지름" << c.radius << "인 " << c.name << ")";
	return ost;
}



int main()
{
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;
}
