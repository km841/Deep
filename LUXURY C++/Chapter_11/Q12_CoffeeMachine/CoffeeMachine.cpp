#include "pch.h"
#include "CoffeeMachine.h"

void CoffeeMachine::makeNormalCoffee()
{
	bool flag = true;
	for (int i = 0; i < 5; i++) {
		if ((containers[i]->getName() == "Coffee") || (containers[i]->getName() == "Water") || (containers[i]->getName() == "Cup"))
		{
			if (containers[i]->isEmpty()) flag = false;
			else v.emplace_back(containers[i]);
		}
	}

	if (flag) {
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->use();
		}
		cout << "맛있는 보통 커피 나왔습니다~~" << endl;
		v.clear();
	}
	else {
		v.clear();
	}
		
}

void CoffeeMachine::makeSugarCoffee()
{
	bool flag = true;
	for (int i = 0; i < 5; i++) {
		if ((containers[i]->getName() == "Coffee") || 
			(containers[i]->getName() == "Water") || 
			(containers[i]->getName() == "Cup") ||
			(containers[i]->getName() == "Sugar"))
		{
			if (containers[i]->isEmpty()) flag = false;
			else v.emplace_back(containers[i]);
		}
	}
		
	if (flag) {
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->use();
		}
		cout << "맛있는 설탕 커피 나왔습니다~~" << endl;
		v.clear();
	}
	else {
		v.clear();
	}
}

void CoffeeMachine::makeBlackCoffee()
{
	bool flag = true;
	for (int i = 0; i < 5; i++) {
		if ((containers[i]->getName() == "Coffee") ||
			(containers[i]->getName() == "Water") ||
			(containers[i]->getName() == "Cup") ||
			(containers[i]->getName() == "Cream"))
		{
			if (containers[i]->isEmpty()) flag = false;
			else v.emplace_back(containers[i]);
		}
	}

	if (flag) {
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->use();
		}
		cout << "맛있는 블랙 커피 나왔습니다~~" << endl;
		v.clear();
	}
	else {
		v.clear();
	}
}

void CoffeeMachine::fill()
{
	for (int i = 0; i < 5; i++)
		containers[i]->fill();
}
