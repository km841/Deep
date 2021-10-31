#include "Book.h"

Book::Book(const char* title, int price)
{
	const size_t size = strlen(title) + 1;
	this->title = new char[size];
	strcpy(this->title, title);
	this->price = price;
}

Book::~Book()
{
	if (title != nullptr)
	{
		delete[] title;
		title = nullptr;
	}
}

Book::Book(const Book& other)
{
	const size_t size = strlen(other.title) + 1;
	this->title = new char[size];
	strcpy(this->title, other.title);
	this->price = other.price;
}

void Book::set(const char* title, int price)
{
	if (this->title != nullptr)
	{
		delete[] this->title;
		this->title = nullptr;
	}

	const size_t size = strlen(title) + 1;
	this->title = new char[size];
	strcpy(this->title, title);
	this->price = price;
}
