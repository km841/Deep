#pragma once
#include <iostream>
#include <string>

using namespace std;


class Person
{
	string name;

public:
	Person() : name() {};
	Person(string name) { this->name = name; };
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

