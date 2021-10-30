#include "Player.h"

Player::Player() : _word(), _name()
{
}
void Player::SetName(string name)
{
	this->_name = name;
}

void Player::SetWord()
{
	string word;
	cout << _name << ">>";
	getline(cin, word);
	this->_word = word;
}

const string& Player::GetWord() const
{
	return this->_word;
}

Player::~Player()
{
}
