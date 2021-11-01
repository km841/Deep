#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
	string _name;
	int _num;

public:
	Person();
	~Person();

	void SetName(string name);
	string GetName();

	void SetNum(int num);
	int GetNum();
};

