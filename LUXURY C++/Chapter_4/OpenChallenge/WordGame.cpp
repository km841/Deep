#include "WordGame.h"

WordGame::WordGame(int n)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	this->_user = n;
	this->_player = new Player[_user];
}

void WordGame::NameSetting()
{
	string temp;
	for (int i = 0; i < _user; i++)
	{
		cout << "참가자의 이름을 입력하세요, 빈칸 없이>>";
		getline(cin, temp, '\n');
	
		_player[i].SetName(temp);
	}
		
}

Player& WordGame::GetPlayer(int n)
{
	return _player[n];
}

string WordGame::Turn(int n)
{
	Player& p = GetPlayer(n);
	p.SetWord();
	return p.GetWord();
}

bool WordGame::WordCompare(string word)
{
	if (IsOverlaped(word))
		return false;

	if (_prev_word[_prev_word.size() - 2] == word[0] &&
		_prev_word[_prev_word.size() - 1] == word[1])
	{
		_prev_words.emplace_back(word);
		_prev_word = word;
		return true;
	}

	return false;
}

bool WordGame::IsOverlaped(const string& word)
{
	return find(_prev_words.begin(), _prev_words.end(), word) != _prev_words.end();
}

string WordGame::StartGame()
{
	int randValue = rand() % _start_words.size();

	_curr_word = _start_words[randValue];
	_prev_word = _start_words[randValue];
	_prev_words.emplace_back(_curr_word);

	return _start_words[randValue];
}

WordGame::~WordGame()
{
	if (_player != nullptr)
	{
		delete[] _player;
		_player = nullptr;
	}
}

