#pragma once
class Book
{
	int year;
	string name;
	string autor;

public:
	Book(int year, string name, string autor) : year(year), name(name), autor(autor) {}
	int getYear();
	string getName();
	string getAutor();
	void show();

	bool operator== (string autor);

};

