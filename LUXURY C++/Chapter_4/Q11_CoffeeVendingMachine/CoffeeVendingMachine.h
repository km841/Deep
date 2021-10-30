#pragma once
#include "Container.h"

enum {
	Espresso = 1,
	Americano,
	SugarCoffee,
	Amount,
	Fill
};


class CoffeeVendingMachine
{
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
	void printMessage();

public:
	void run();
};

