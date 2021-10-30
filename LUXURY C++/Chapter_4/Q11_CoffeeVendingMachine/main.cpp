#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "CoffeeVendingMachine.h"
using namespace std;



int main() 
{
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	CoffeeVendingMachine machine;

	while (true)
	{
		machine.run();
	}

}
