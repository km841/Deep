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

	Book& operator+=(int n);
	Book& operator-=(int n);

};

