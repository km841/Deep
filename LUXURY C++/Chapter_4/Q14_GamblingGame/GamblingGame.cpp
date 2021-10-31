#include "GamblingGame.h"

GamblingGame::GamblingGame()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	_players = new Player[MAX_USER];
}

GamblingGame::~GamblingGame()
{
	if (_players != nullptr)
	{
		delete[] _players;
		_players = nullptr;
	}
}

void GamblingGame::SetPlayerName()
{
	for (int i = 0; i < MAX_USER; i++)
	{
		if (i == 0) cout << "첫 번째 선수 이름>>";
		else cout << "두 번째 선수 이름>>";

		string name;
		getline(cin, name);

		_players[i].SetName(name);
	}
}

bool GamblingGame::NextTurn(int n)
{
	cout << _players[n].GetName() << ":" << "<Enter>";
	while (getchar() != '\n') {};

	int* checkNum = _players[n].SetNumbers();

	cout << '\t' << '\t';

	for (int i = 0; i < MAX_NUMS; i++)
	{
		cout << checkNum[i] << '\t';
	}

	if (checkNum[0] == checkNum[1] && checkNum[1] == checkNum[2]) {
		cout << _players[n].GetName() << "님의 승리!!" << endl;
		return false;
	}

	else {
		cout << "아쉽군요!" << endl;
		return true;
	}
}

