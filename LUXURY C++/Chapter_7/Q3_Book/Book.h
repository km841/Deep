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
	friend bool operator== (Book& b, int price);
	friend bool operator== (Book& b, string title);
	friend bool operator== (Book& b, const Book& book);
	bool operator! () { return price == 0; }

};

