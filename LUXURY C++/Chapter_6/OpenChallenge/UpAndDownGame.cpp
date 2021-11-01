#include "UpAndDownGame.h"
#include "Person.h"

UpAndDownGame::UpAndDownGame()
{
	
	cout << "이름을 정하세요" << endl;
	for (int i = 0; i < GAMER_MAX; i++)
	{
		string name;
		getline(cin, name);

		p[i].SetName(name);
	}
}

UpAndDownGame::~UpAndDownGame()
{}

bool UpAndDownGame::Turn(int n)
{

	Person& curr = p[n];
	cout << curr.GetName() << ">>";

	int input;
	cin >> input;
	cin.ignore();

	if (_ans == input) {
		cout << curr.GetName() << "가 이겼습니다!!" << endl;
		return false;
	}

	// 입력한 값이 정답보다 작으면 최대값을 입력값으로

	else if (_ans > input) _min = input;
	else if (_ans < input) _max = input;

	cout << "답은 " << _min << "과 " << _max << "사이에 있습니다." << endl;
	return true;
}

