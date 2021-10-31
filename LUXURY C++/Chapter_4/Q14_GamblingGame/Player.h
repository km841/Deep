#pragma once
#include <string>
#include <iostream>
using namespace std;

const int MAX_NUMS = 3;

class Player
{
	int* _nums;
	string _name;

public:
	Player();
	~Player();
	int* SetNumbers();
	void SetName(string name);
	string GetName();
};
