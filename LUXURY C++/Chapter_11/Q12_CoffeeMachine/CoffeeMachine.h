#pragma once
#include "Water.h"
#include "Sugar.h"
#include "Coffee.h"
#include "Cream.h"
#include "Cup.h"

class CoffeeMachine
{
	Container* containers[5];
	vector<Container*> v;

public:
	CoffeeMachine() {
		containers[0] = new Coffee("Coffee");
		containers[1] = new Sugar("Sugar");
		containers[2] = new Cream("Cream");
		containers[3] = new Water("Water");
		containers[4] = new Cup("Cup");
	}

	void makeNormalCoffee();
	void makeSugarCoffee();
	void makeBlackCoffee();
	void fill();

	friend ostream& operator<< (ostream& ost, CoffeeMachine& cof);


	~CoffeeMachine() {
		for (int i = 0; i < 5; i++) delete containers[i];
	}

};

