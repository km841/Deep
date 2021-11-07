#include "pch.h"
#include "Book.h"
#include "Product.h"

Book::Book() {}

void Book::Set(int id)
{
	string prodCont;
	string prodName;
	int price;
	string bookname;
	string autor;
	int isbn;

	cout << "상품설명>>";
	getline(cin, prodCont);

	cout << "생산자>>";
	getline(cin, prodName);

	cout << "가격>>";
	cin >> price;
	cin.ignore();

	cout << "책제목>>";
	getline(cin, bookname);

	cout << "저자>>";
	getline(cin, autor);

	cout << "ISBN>>";
	cin >> isbn;
	cin.ignore();

	_prodCont = prodCont;
	_prodName = prodName;
	_price = price;
	_bookName = bookname;
	_autor = autor;
	_isbn = isbn;
	_id = id;

	
}

void Book::Show()
{
	cout << "--- 상품ID : " << _id << endl;
	cout << "상품설명 : " << _prodCont << endl;
	cout << "생산자 : " << _prodName << endl;
	cout << "가격 : " << _price << endl;
	cout << "책제목 : " << _bookName << endl;
	cout << "저자 : " << _autor << endl;
	cout << "ISBN : " << _isbn << endl << endl;
}
