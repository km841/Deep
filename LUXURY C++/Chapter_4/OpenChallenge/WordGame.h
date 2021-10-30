#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"

using namespace std;

class WordGame
{
private:
	Player* _player;
	int _user;
	int _turn;

	string _prev_word;
	string _curr_word;

	vector<string> _start_words{
		"아버지", "개나리", "리본", "감자", "백화점"
	};

	vector<string> _prev_words;

public:
	WordGame(int n);
	void NameSetting();
	Player& GetPlayer(int n);
	string Turn(int n);
	bool WordCompare();
	bool IsOverlaped(const string& word);
	string StartGame();


	~WordGame();
};

