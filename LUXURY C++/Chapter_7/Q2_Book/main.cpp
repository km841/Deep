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
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;
	if (a == "명품 C++") cout << "명품 C++입니다." << endl;
	if (a == b) cout << "두 책이 같은 책입니다." << endl;

}
