#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book
{
	string title;
	int price, pages;

public:
	Book(string title = "", int price = 0, int pages = 0);
	void show();
	string getTitle();

	friend const Book& operator+= (Book& b, int n);
	friend const Book& operator-= (Book& b, int n);

};

