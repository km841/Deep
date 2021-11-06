#include "Book.h"

Book::Book(string title, int price, int pages)
{
	this->title = title;
	this->price = price;
	this->pages = pages;
}

void Book::show()
{
	cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
}

string Book::getTitle()
{
	return title;
}

bool Book::operator==(int price)
{
	return this->price == price;
}

bool Book::operator==(string title)
{
	return this->title == title;
}

bool Book::operator==(const Book& book)
{
	return (this->title == book.title && this->price == book.price);
}
