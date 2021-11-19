#include "pch.h"
#include "HangmanGame.h"
#include "User.h"

int main()
{
	cout << "------------------------------" << endl;
	cout << "지금부터 행맨 게임을 시작합니다." << endl;
	cout << "------------------------------" << endl;

	HangmanGame game;
	game.fileLoad();

	while (game.question()) {}

	return 0;
}

