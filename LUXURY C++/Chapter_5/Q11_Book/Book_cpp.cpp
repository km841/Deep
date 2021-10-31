#include "Book.h"

Book::Book(string title, int price)
{
	this->title = title;
	this->price = price;
}

Book::~Book()
{}

void Book::set(string title, int price)
{
	this->title = title;
	this->price = price;
}
