#include "pch.h"
#include "Book.h"

int Book::getYear()
{
	return year;
}

string Book::getName()
{
	return name;
}

string Book::getAutor()
{
	return autor;
}

void Book::show()
{
	cout << year << "년도, " << name << ", " << autor << endl;
}

bool Book::operator==(string autor)
{
	return this->autor == autor;
}
