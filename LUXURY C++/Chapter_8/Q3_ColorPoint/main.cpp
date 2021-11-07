#include "pch.h"
#include <iostream>
#include <string>
#include "ColorPoint.h"


using namespace std;

int main()
{
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
	

}

