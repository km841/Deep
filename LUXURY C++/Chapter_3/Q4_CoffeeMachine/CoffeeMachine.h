#pragma once
#include <iostream>
using namespace std;
const char MAX_FILL = 10;

class CoffeeMachine
{
private:
	int coffee, water, sugar;

public:
	CoffeeMachine(int c, int w, int s);
	
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugerCoffee();

	void show();
	void fill();


};

