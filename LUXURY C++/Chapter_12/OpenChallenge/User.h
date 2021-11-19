#pragma once
class User
{
	int challenge;
public:
	User(int chall = 5) : challenge(chall) {}
	void game_try() { 
		challenge--; 
	}

	void init() { challenge = 5; }
	int get_try() { return challenge; }
	char answer();
};

