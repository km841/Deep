#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Histogram
{
	int* _hist;
	size_t _size = 0;

public:
	Histogram(string word);
	Histogram& operator<< (string word);
	Histogram& operator<< (char word);

	void operator! ();

	~Histogram();
	
	
	
	
	

};

