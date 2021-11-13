#pragma once
#include "Word.h"
class WordGame
{
	vector<Word> wordBook;
	size_t wordSize;

public:
	WordGame();
	void init();
	void add(string kor, string eng);
	bool Questions();

};

