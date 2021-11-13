#pragma once
#include <iostream>
#include <string>
using namespace std;


class Shape
{
protected:
	Shape* next;
	
public:
	Shape() : next(nullptr) {}
	void add(Shape* p) { this->next = p; }
	void del() { this->next = nullptr; }
	Shape* getNext() { return next; }
	virtual string getShape() = 0;
	virtual ~Shape() {};


};

