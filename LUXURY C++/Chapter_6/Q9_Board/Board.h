#pragma once
#include <iostream>
#include <string>
using namespace std;

class Board
{
public:
	static string strArr[100];
	static int arrPos;

	static void add(string message);
	static void print();
};

