#pragma once
#include "Product.h"
class Book : public Product
{
protected:
	int _isbn;
	string _bookName;
	string _autor;

public:
	Book();
	void Set(int id);
	void Show();
};

