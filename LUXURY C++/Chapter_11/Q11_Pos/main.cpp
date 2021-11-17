#include "pch.h"


istream& pos(istream& ist)
{
	cout << "위치는? ";
	return ist;
}

int main()
{
	int x, y;
	cin >> pos >> x;
	cin >> pos >> y;
	cout << x << ',' << y << endl;
	
}
