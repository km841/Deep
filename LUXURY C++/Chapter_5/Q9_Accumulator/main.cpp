#include <iostream>
#include <string>
#include "Accumulator.h"
using namespace std;



int main()
{
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();
}

