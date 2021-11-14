#pragma once
#include "Nation.h"
class CountrysCapitalGame
{
	vector<Nation> v;

public:
	void init();
	bool add(string country, string capital);
	bool quiz();
	const vector<Nation>& getVector();

};

