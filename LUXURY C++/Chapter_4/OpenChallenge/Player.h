#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{
private:
	string _word;
	string _name;

public:
	Player();
	void SetName(string name);
	void SetWord();
	const string& GetWord() const;
	

	~Player();
};

