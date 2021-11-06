#pragma once
#include <iostream>
using namespace std;

class Statistics
{
	int* stat;
	size_t size;
	size_t capacity;
public:
	Statistics();
	void realloc_size();

	bool operator! ();
	Statistics& operator<< (int n);
	int& operator>> (int& n);
	void operator~ ();

	~Statistics();
};

