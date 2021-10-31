#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "GamblingGame.h"

using namespace std;



int main()
{
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	GamblingGame gg;
	gg.SetPlayerName();
	int _turn = 0;

	do
	{
		_turn %= 2;

	} while (gg.NextTurn(_turn++));

}
