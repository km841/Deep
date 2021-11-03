#pragma once
#include <iostream>
#include <string>
using namespace std;

class Random
{
public:
	static void seed() { srand((unsigned int)time(nullptr)); }
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();

};

