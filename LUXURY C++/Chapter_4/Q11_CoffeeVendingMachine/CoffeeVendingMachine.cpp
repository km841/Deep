#include "CoffeeVendingMachine.h"
#include "Container.h"

void CoffeeVendingMachine::fill()
{
	for (int i = 0; i < 3; i++)
	{
		tong[i].fill();
	}
	this->show();
}

void CoffeeVendingMachine::selectEspresso()
{
	if (tong[0].getSize() && tong[1].getSize())
	{
		tong[0].consume(); tong[1].consume();
		cout << "에스프레소 드세요" << endl;
	}

	else
		cout << "원료가 부족합니다." << endl;
}

void CoffeeVendingMachine::selectAmericano()
{
	if (tong[0].getSize() && tong[1].getSize() >= 1)
	{
		tong[0].consume(); tong[1].consume(); tong[1].consume();
		cout << "아메리카노 드세요" << endl;
	}

	else
		cout << "원료가 부족합니다." << endl;
}

void CoffeeVendingMachine::selectSugarCoffee()
{
	if (tong[0].getSize() && tong[1].getSize() >= 1 && tong[2].getSize())
	{
		tong[0].consume(); tong[1].consume(); tong[1].consume(); tong[2].consume();
		cout << "설탕커피 드세요" << endl;
	}

	else
		cout << "원료가 부족합니다." << endl;
}

void CoffeeVendingMachine::show()
{
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::printMessage()
{
	cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
}

void CoffeeVendingMachine::run()
{
	printMessage();
	int select = 0;

	cin >> select;
	cin.ignore();

	switch (select)
	{
	case Espresso:
		this->selectEspresso();
		break;

	case Americano:
		this->selectAmericano();
		break;

	case SugarCoffee:
		this->selectSugarCoffee();
		break;

	case Amount:
		this->show();
		break;

	case Fill:
		this->fill();
		break;

	default:
		break;

	}

}
