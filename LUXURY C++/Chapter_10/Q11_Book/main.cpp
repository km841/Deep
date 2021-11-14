#include "pch.h"
#include "Book.h"

int main()
{
	vector<Book> v;
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;

	while (true)
	{
		int year;
		cout << "년도>>";
		cin >> year;
		cin.ignore();

		if (year == -1) break;

		string name, autor;
		cout << "책이름>>";
		getline(cin, name);

		cout << "저자>>";
		getline(cin, autor);

		v.emplace_back(year, name, autor);
	}

	cout << "총 입고된 책은 " << v.size() << "권 입니다." << endl;
	cout << "검색하고자 하는 저자 이름을 입력하세요>>";
	string search_autor;
	getline(cin, search_autor);
	
	for (int i = 0; i < v.size(); i++)
		if (v[i].getAutor() == search_autor) v[i].show();


	cout << "검색하고자 하는 년도를 입력하세요>>";
	int search_year;
	cin >> search_year;
	cin.ignore();

	for (int i = 0; i < v.size(); i++)
		if (v[i].getYear() == search_year) v[i].show();

}
