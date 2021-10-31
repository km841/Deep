#include "CircleManager.h"

CircleManager::CircleManager(int size)
{
	this->size = size;
	p = new Circle[size];

	for (int i = 0; i < size; i++)
	{
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		string c;

		getline(cin, c);
		int sep = c.find(' ');
		p[i].setCircle(c.substr(0, sep), stoi(c.substr(sep + 1)));
	}

}

CircleManager::~CircleManager()
{
	if (p != nullptr)
	{
		delete[] p;
		p = nullptr;
	}
}

void CircleManager::searchByName()
{
	cout << "검색하고자 하는 원의 이름 >> ";
	string userInput;
	getline(cin, userInput);


	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == userInput)
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
	}
}

void CircleManager::searchByArea()
{
	cout << "최소 면적을 정수로 입력하세요 >> ";
	int userInput;
	cin >> userInput;
	cin.ignore();
	

	cout << userInput << "보다 큰 원을 검색합니다." << endl;


	for (int i = 0; i < size; i++)
	{
		if (p[i].getArea() >= userInput)
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ",";
	}
}
