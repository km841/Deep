#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person;

class Family
{
	Person* p;
	int size;

public:
	Family(string name, int size);
	void show();
	void setName(int n, string name);

	~Family();


};

