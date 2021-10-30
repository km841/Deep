#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "WordGame.h"
using namespace std;

int main() 
{
	cout << "끝말 잇기 게임을 시작합니다." << endl;
	cout << "게임에 참가하는 인원은 몇명입니까? ";
	
	int n = 0;
	cin >> n;
	cin.ignore();

	if (n <= 1) {
		cout << "혼자서는 게임을 할 수 없습니다!" << endl;
		return 0;
	}

	WordGame wg(n);
	wg.NameSetting();
	string startWord = wg.StartGame();
	cout << startWord << endl;

	int turn = 0;
	string word;

	do
	{
		if (turn == n) turn = 0;
		word = wg.Turn(turn++);

	} while (wg.WordCompare(word));

	cout << "게임이 끝났습니다!" << endl;
}

