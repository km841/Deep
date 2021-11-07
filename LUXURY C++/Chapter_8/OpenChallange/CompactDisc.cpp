#include "pch.h"
#include "CompactDisc.h"
#include "Product.h"

CompactDisc::CompactDisc() {}

void CompactDisc::Set(int id)
{
	string prodCont;
	string prodName;
	int price;
	string albumname;
	string singer;

	cout << "상품설명>>";
	getline(cin, prodCont);

	cout << "생산자>>";
	getline(cin, prodName);

	cout << "가격>>";
	cin >> price;
	cin.ignore();

	cout << "앨범제목>>";
	getline(cin, albumname);

	cout << "가수>>";
	getline(cin, singer);

	
}

void CompactDisc::Show()
{
	cout << "--- 상품ID : " << _id << endl;
	cout << "상품설명 : " << _prodCont << endl;
	cout << "생산자 : " << _prodName << endl;
	cout << "가격 : " << _price << endl;
	cout << "앨범제목 : " << _albumName << endl;
	cout << "가수 : " << _singer << endl << endl;
}
