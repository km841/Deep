#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book
{
	char* title;
	int price;

public:
	Book(const char* title, int price);
	~Book();
	Book(const Book& other);
	
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

