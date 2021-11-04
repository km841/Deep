#include "Histogram.h"

Histogram::Histogram(string word) : _hist(new int[26])
{
	memset(_hist, 0, 26 * sizeof(int));

	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] >= 65 && word[i] <= 90) word[i] += 32;
		if (word[i] >= 97 && word[i] <= 122)
		{
			_hist[word[i] - 97]++;
			_size++;
		}
	}
}

Histogram& Histogram::operator<<(string word)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] >= 65 && word[i] <= 90) word[i] += 32;
		if (word[i] >= 97 && word[i] <= 122)
		{
			_hist[word[i] - 97]++;
			_size++;
		}
	}
	return *this;
}

Histogram& Histogram::operator<<(char word)
{
	if (word >= 65 && word <= 90) word += 32;
	if (word >= 97 && word <= 122)
	{
		_hist[word - 97]++;
		_size++;
	}
	return *this;
}

void Histogram::operator!()
{
	cout << "총 알파벳 수 " << _size << endl;
	for (int i = 0; i < 26; i++)
	{
		cout << (char)(i + 97) << ":";

		for (int j = 0; j < _hist[i]; j++)
			cout << "*";

		cout << endl;
	}
}

Histogram::~Histogram()
{
	if (_hist != nullptr)
	{
		delete[] _hist;
		_hist = nullptr;
	}
}
