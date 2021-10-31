#include "Histogram.h"

Histogram::Histogram() : Histogram("") {}

Histogram::Histogram(string word) : _content(word)
{
	for (int i = alpha_a; i < alpha_z; i++)
	{
		this->_keyMap[i] = 0;
	}
}

Histogram::~Histogram()
{
}

void Histogram::put(string word)
{
	this->_content.append(word);
}

void Histogram::putc(char c)
{
	this->_content.append(&c);
}

void Histogram::print()
{
	for (int i = 0; i < _content.size(); i++)
	{
		if (_content[i] >= alpha_a && _content[i] <= alpha_z - 1)
			_keyMap[_content[i]] += 1;
	}

	for (const auto& c : _keyMap)
	{
		cout << c.first << "(" << c.second << ")" << '\t' << " : ";
		for (int i = 0; i < c.second; i++)
			cout << "*";
		cout << endl;
	}

}
