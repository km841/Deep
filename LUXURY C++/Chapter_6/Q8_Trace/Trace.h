#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using TraceTuple = pair<string, string>;

class Trace
{
	static vector<TraceTuple> _traceVector;

public:
	static void put(string tag, string info);
	static void print(string tag);
	static void print();

};

