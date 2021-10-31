#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book
{
	string title;
	int price;

public:
	Book(string title, int price);
	~Book();
	
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

