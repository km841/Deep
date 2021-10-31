#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;


class Morse
{
	string alphabet[26];
	string digit[10];
	string slash, question, comma, period, plus, equal;

	map<string, string> t2m;
	map<string, string> m2t;

public:
	Morse();
	void text2Morse(string text, string& morse);
	bool morse2Test(string morse, string& text);
};

