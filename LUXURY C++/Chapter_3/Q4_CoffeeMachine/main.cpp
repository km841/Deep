#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CoffeeMachine.h"
using namespace std;



int main()
{
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugerCoffee();
	java.show();
	java.fill();
	java.show();

}

