#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

const Book& operator+= (Book& b, int n)
{
	b.price += n;
	return b;
}

const Book& operator-= (Book& b, int n)
{
	b.price -= n;
	return b;
}

bool operator== (Book& b, int price)
{
	return b.price == price;
}
bool operator== (Book& b, string title)
{
	return b.title == title;
}
bool operator== (Book& b, const Book& book)
{
	return (b.title == book.title && b.price == book.price);
}

int main()
{
	Book book("벼룩시장", 0, 50);
	if (!book) cout << "공짜다" << endl;

}
