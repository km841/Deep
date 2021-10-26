#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine(int c, int w, int s) : coffee(c), water(w), sugar(s)
{
}

void CoffeeMachine::drinkEspresso()
{
	coffee -= 1;
	water -= 1;
}

void CoffeeMachine::drinkAmericano()
{
	coffee -= 1;
	water -= 2;
}

void CoffeeMachine::drinkSugerCoffee()
{
	coffee -= 1;
	water -= 2;
	sugar -= 1;
}

void CoffeeMachine::show()
{
	cout << "커피 머신 상태, 커피:" << coffee << " 물: " << water << " 설탕 :" << sugar << endl;
}

void CoffeeMachine::fill()
{
	coffee = water = sugar = MAX_FILL;
}
