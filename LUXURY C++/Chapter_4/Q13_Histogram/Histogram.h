#pragma once
#include <string>
#include <iostream>
#include <map>
using namespace std;

const int alpha_a = 97;
const int alpha_z = 122 + 1;

class Histogram
{
	string _content;
	map<char, int> _keyMap;

public:
	Histogram();
	Histogram(string word);
	~Histogram();

	void put(string word);
	void putc(char c);
	void print();
};

