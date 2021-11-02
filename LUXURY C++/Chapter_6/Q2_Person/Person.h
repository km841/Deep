#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
	int id;
	double weight;
	string name;

public:
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
	Person(int id = 1, string name = "Grace", double weight = 20.5);

};

