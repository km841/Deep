#include "pch.h"
#include "CoffeeMachine.h"


ostream& info(ostream& ost) {
	ost << "------명품 커피 자판기켭니다.------" << endl;
	return ost;
}

ostream& menu(ostream& ost) {
	ost << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4>>";
	return ost;
}

ostream& operator<< (ostream& ost, CoffeeMachine& cof)
{
	for (int i = 0; i < 5; i++)
	{
		ost << setw(10) << left << cof.containers[i]->getName();
		for (int j = 0; j < cof.containers[i]->getSize(); j++)
			ost << "*";
		ost << endl;
	}

	return ost;
}

int main()
{
	CoffeeMachine coffeeMachine;

	cout << info;

	int ch = 1;
	while (ch >= 0 && ch < 4) {
		cout << coffeeMachine << endl;
		cout << menu;

		cin >> ch;
		cin.ignore();

		switch (ch)
		{
		case 0: 
			coffeeMachine.makeNormalCoffee();
			break;
		case 1: 
			coffeeMachine.makeSugarCoffee();
			break;
		case 2: 
			coffeeMachine.makeBlackCoffee();
			break;
		case 3:
			coffeeMachine.fill();
			break;
		}
	}

}
