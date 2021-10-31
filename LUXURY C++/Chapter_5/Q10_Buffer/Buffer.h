#pragma once
#include <iostream>
#include <string>
using namespace std;
class Buffer
{
	string text;

public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void print() { cout << text << endl; }
};

